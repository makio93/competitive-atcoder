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

const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n+1);
	s[0] = string(m, '.');
	rep3(i, 1, n+1) cin >> s[i];
	rep3(i, 1, n) rep(j, m) if (s[i][j] == '#') {
		s[i+1][j] = '#';
		if (j+1 < m) s[i+1][j+1] = '#';
	}
	rep(i, n+1) s[i].push_back('#');
	vector<vector<ll>> dp(m+n+1, vector<ll>(m+1));
	dp[0][m] = 1;
	rep3(i, 1, m+n+1) {
		dp[i][m] = dp[i-1][m];
		repr(j, m) dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % mod;
		rep(j, m) {
			if (i-m+j <= 0) {
				dp[i][j] = 0;
				continue;
			}
			if (i-m+j > n || s[i-m+j][j] == '#') dp[i][j+1] = 0;
		}
	}
	ll res = 0;
	rep(i, m+1) res = (res + dp[m+n][i]) % mod;
	cout << res << endl;
	return 0;
}
