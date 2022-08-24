// 学習1回目,自力AC

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

const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dp(n+1, vector<ll>(1<<m));
	dp[0][0] = 1;
	rep(i, n) rep(j, 1<<m) if (__builtin_popcount(j) <= 3) {
		vector<int> vals;
		rep(i2, m) if ((j>>i2)&1) vals.push_back(i2);
		rep(i2, m) {
			auto tvals = vals;
			if (tvals.empty() || tvals.back()<i2) tvals.push_back(i2);
			else {
				rep(j2, (int)(tvals.size())) if (tvals[j2] >= i2) {
					tvals[j2] = i2;
					break;
				}
			}
			if ((int)(tvals.size()) > 3) continue;
			int tj = 0;
			for (int id : tvals) tj |= 1<<id;
			dp[i+1][tj] = (dp[i+1][tj] + dp[i][j]) % mod;
		}
	}
	ll res = 0;
	rep(i, 1<<m) if (__builtin_popcount(i) == 3) res = (res + dp[n][i]) % mod;
	cout << res << endl;
	return 0;
}
