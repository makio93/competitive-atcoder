// 本番AC

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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll res = n;
	rep3(i1, 2, n+1) {
		vector<vector<ll>> dp(i1+1, vector<ll>(i1));
		dp[0][0] = 1;
		rep(i, n) {
			auto ndp = dp;
			rep(j1, i1) rep(j2, i1) ndp[j1+1][(j2+a[i])%i1] = (ndp[j1+1][(j2+a[i])%i1] + dp[j1][j2]) % mod;
			swap(ndp, dp);
		}
		res = (res + dp[i1][0]) % mod;
	}
	cout << res << endl;
	return 0;
}
