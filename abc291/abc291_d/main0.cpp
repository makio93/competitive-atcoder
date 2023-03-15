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

const int INF = (int)(1e9);
const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> ab(n, vector<int>(2));
	rep(i, n) cin >> ab[i][0] >> ab[i][1];
	vector<vector<ll>> dp(n, vector<ll>(2));
	dp[0][0] = dp[0][1] = 1;
	rep3(i, 1, n) rep(j1, 2) rep(j2, 2) if (ab[i][j1] != ab[i-1][j2]) {
		dp[i][j1] += dp[i-1][j2];
		dp[i][j1] %= mod;
	}
	ll res = 0;
	rep(i, 2) res = (res + dp[n-1][i]) % mod;
	cout << res << endl;
	return 0;
}
