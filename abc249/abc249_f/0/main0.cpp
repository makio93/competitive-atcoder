// 本番終了後,自力AC

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
	int n, k;
	cin >> n >> k;
	vector<int> t(n), y(n);
	rep(i, n) cin >> t[i] >> y[i];
	ll res = (ll)(-1e18);
	if (k == 0) {
		res = 0;
		rep(i, n) {
			if (t[i] == 1) res = y[i];
			else res += y[i];
		}
	}
	else {
		vector<ll> zero(n+1);
		rep(i, n) {
			if (t[i] == 1) zero[i+1] = y[i];
			else zero[i+1] = zero[i] + y[i];
		}
		res = zero[n];
		multiset<ll> neg;
		neg.insert(0);
		auto itr = neg.begin();
		vector<ll> ysum(n+2);
		int ocnt = 0;
		ll nsum = 0;
		repr(i, n) {
			if (k-ocnt < 0) break;
			if (t[i] == 2) {
				if (y[i] >= 0) ysum[i+1] = ysum[i+2] + y[i];
				else {
					neg.insert(y[i]);
					if ((int)(neg.size())-1 > k-ocnt) {
						if (y[i] >= *itr) nsum += y[i];
						else {
							--itr;
							nsum += *itr;
						}
					}
					ysum[i+1] = ysum[i+2];
				}
			}
			else {
				ysum[i+1] = ysum[i+2];
				res = max(res, y[i]+ysum[i+1]+nsum);
				++ocnt;
				if ((int)(neg.size())-1 > k-ocnt) {
					--itr;
					nsum += *itr;
				}
			}
		}
		if (k-ocnt >= 0) {
			ysum[0] = ysum[1];
			res = max(res, ysum[0]+nsum);
		}
	}
	cout << res << endl;
	return 0;
}
