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
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<ll>> dp(n+1, vector<ll>(n+1));
	dp[0][0] = 1;
	rep(i, n) rep(j, n+1) {
		if (s[i] == '(' && j+1 <= n) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
		if (s[i] == ')' && j-1 >= 0) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % mod;
		if (s[i] == '?') {
			if (j+1 <= n) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
			if (j-1 >= 0) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % mod;
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}
