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
const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<vector<vector<ll>>>> dp(n, vector<vector<vector<ll>>>(n, vector<vector<ll>>(m+1, vector<ll>(11))));
	rep(i, n) rep(k, 11) dp[i][0][0][k] = 1;
	rep(j, n) for (int i=0; i+j<n; ++i) rep3(k, 1, m+1) repr(l, 10) {
		dp[i][j][k][l] += dp[i][j][k][l+1];
		dp[i][j][k][l] %= mod;
		if (s[i][m-k]!='?' && s[i][m-k]-'0'<l) continue;
		bool ok = true;
		int mval = (s[i][m-k] == '?') ? l : s[i][m-k]-'0';
		rep(j2, j) {
			if (s[i+1][m-k]!='?' && s[i+1][m-k]-'0'<mval) {
				ok = false;
				break;
			}
			if (s[i+1][m-k] != '?') mval = max(mval, s[i+1][m-k]-'0');
		}
		if (!ok) continue;
		rep(j2, j+1) {
			if (s[i+j2][m-k]!='?' && s[i+j2][m-k]-'0'!=l) break;
			if (j2 < j) dp[i][j][k][l] += dp[i][j2][k-1][0] * dp[i+j2+1][j-j2-1][k][l+1] % mod;
			else dp[i][j][k][l] += dp[i][j2][k-1][0];
			dp[i][j][k][l] %= mod;
		}
	}
	cout << dp[0][n-1][m][0] << endl;
	return 0;
}
