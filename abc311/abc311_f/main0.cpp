// 自力WA

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
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(4)));
	rep(i, m) rep(i2, 4) {
		int li = i2 / 2, ri = i2 % 2;
		if ((li == 1 && i-1 < 0) || (li == 0 && i-1 >= 0 && s[0][i-1] == '#') || (ri == 0 && s[0][i] == '#')) continue;
		dp[0][i][i2] = 1;
	}
	rep3(i, 1, n) rep(j, m) rep(i2, 4) {
		int li = i2 / 2, ri = i2 % 2;
		if ((li == 1 && j-1 < 0) || (li == 0 && j-1 >= 0 && s[i][j-1] == '#') || (ri == 0 && s[i][j] == '#')) continue;
		dp[i][j][i2] += dp[i-1][j][0];
		if (ri == 1) {
			dp[i][j][i2] += dp[i-1][j][1];
			if (li == 1) rep3(j2, 2, 4) dp[i][j][i2] += dp[i-1][j][j2];
		}
		dp[i][j][i2] %= mod;
		ll lval = 0;
		if (j-1 >= 0) { rep(j2, 4) if ((li == 0 && j2%2 == 0) || (li == 1 && j2%2 == 1)) lval += dp[i][j-1][j2]; }
		else lval = 1;
		dp[i][j][i2] = dp[i][j][i2] * lval % mod;
	}
	ll res = 0;
	rep(i, 4) res += dp[n-1][m-1][i];
	res %= mod;
	cout << res << endl;
	return 0;
}
