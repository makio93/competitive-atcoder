// 学習1回目,解説AC

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
	vector<vector<vector<vector<ll>>>> dp(n+1, vector<vector<vector<ll>>>(m+1, vector<vector<ll>>(m+1, vector<ll>(m+1))));
	dp[0][m][m][m] = 1;
	rep(i, n) rep(j1, m+1) rep(j2, m+1) rep(j3, m+1) rep(k, m) {
		if (k <= j1) dp[i+1][k][j2][j3] = (dp[i+1][k][j2][j3] + dp[i][j1][j2][j3]) % mod;
		else if (k <= j2) dp[i+1][j1][k][j3] = (dp[i+1][j1][k][j3] + dp[i][j1][j2][j3]) % mod;
		else if (k <= j3) dp[i+1][j1][j2][k] = (dp[i+1][j1][j2][k] + dp[i][j1][j2][j3]) % mod;
	}
	ll res = 0;
	rep(i1, m) rep3(i2, i1+1, m) rep3(i3, i2+1, m) res = (res + dp[n][i1][i2][i3]) % mod;
	cout << res << endl;
	return 0;
}
