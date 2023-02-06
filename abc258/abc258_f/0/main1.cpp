// 解説AC

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

const int INF = (int)(1e9);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int b, k, sx, sy, gx, gy;
		cin >> b >> k >> sx >> sy >> gx >> gy;
		vector<pair<pair<int, int>, ll>> slst, glst;
		auto makelist = [&](vector<pair<pair<int, int>, ll>>& lst, int xi, int yi) -> void {
			int xl = xi / b * b, xr = xl + b, yd = yi / b * b, yu = yd + b;
			for (int txi : { xl, xr }) lst.emplace_back(make_pair(txi, yi), (ll)abs(txi-xi)*k);
			for (int tyi : { yd, yu }) lst.emplace_back(make_pair(xi, tyi), (ll)abs(tyi-yi)*k);
		};
		makelist(slst, sx, sy);
		makelist(glst, gx, gy);
		ll res = ((ll)abs(sx-gx) + (ll)abs(sy-gy)) * k;
		rep(i, 4) rep(j, 4) {
			int x1 = slst[i].first.first, y1 = slst[i].first.second, x2 = glst[j].first.first, y2 = glst[j].first.second;
			ll dval = 0;
			if ((x1%b==0&&y1%b==0) || (x2%b==0&&y2%b==0)) dval = (ll)abs(x1-x2) + (ll)abs(y1-y2);
			else if (x1%b==0 && x2%b==0 && y1/b==y2/b) {
				dval = min({ (ll)abs(x1-x2)*k+abs(y1-y2), (ll)abs(x1-x2)+y1%b+y2%b, (ll)abs(x1-x2)+(b-y1%b)+(b-y2%b) });
			}
			else if (y1%b==0 && y2%b==0 && x1/b==x2/b) {
				dval = min({ (ll)abs(y1-y2)*k+abs(x1-x2), (ll)abs(y1-y2)+x1%b+x2%b, (ll)abs(y1-y2)+(b-x1%b)+(b-x2%b) });
			}
			else dval = (ll)abs(x1-x2) + (ll)abs(y1-y2);
			res = min(res, dval+slst[i].second+glst[j].second);
		}
		cout << res << endl;
	}
	return 0;
}
