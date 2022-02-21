// 本番終了後,ほぼ自力考察,AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		vector<int> x(n);
		vector<vector<int>> y(n);
		rep(i, n) {
			int yi;
			cin >> x[i] >> yi;
			y[i].push_back(yi);
		}
		vector<ll> b, a;
		b.push_back(0);
		a.push_back(0);
		rep(i, n) {
			ll tb = b.back() + (ll)(x[i]) * y[i][0];
			if (b.back()>0 && tb<0 && x[i]<0 && b.back()+(ll)(x[i])>0) {
				ll ty = b.back() / abs(x[i]), ny = y[i][0] - ty;
				y[i][0] = ty;
				y[i].push_back(ny);
				ll nb = b.back() + (ll)(x[i]) * y[i][0];
				b.push_back(nb);
				b.push_back(tb);
			}
			else if (i==0 || (x[i]>0 && b.back()+(ll)(x[i])<0)) {
				ll ty = 1, ny = y[i][0] - ty;
				y[i][0] = ty;
				y[i].push_back(ny);
				ll nb = b.back() + (ll)(x[i]) * y[i][0];
				b.push_back(nb);
				b.push_back(tb);
			}
			else b.push_back(tb);
		}
		int bid = 0;
		ll res = (ll)(-4e18);
		rep(i, n) {
			if ((int)(y[i].size()) >= 2) {
				ll abl = a.back();
				a.push_back(abl + b[bid]*y[i][0] + (ll)(y[i][0])*(y[i][0]+1)/2*x[i]);
				res = max(res, a.back());
				++bid;
				abl = a.back();
				a.push_back(abl + b[bid]*y[i][1] + (ll)(y[i][1])*(y[i][1]+1)/2*x[i]);
				res = max(res, a.back());
			}
			else {
				ll abl = a.back();
				a.push_back(abl + b[bid]*y[i][0] + (ll)(y[i][0])*(y[i][0]+1)/2*x[i]);
				res = max(res, a.back());
			}
			++bid;
		}
		cout << res << endl;
	}
	return 0;
}
