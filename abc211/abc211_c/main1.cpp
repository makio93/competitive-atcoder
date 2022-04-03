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

const ll mod = (ll)(1e9) + 7;
const string tar = "chokudai";

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<ll>> dp(n+1, vector<ll>(9));
	rep(i, n+1) dp[i][0] = 1;
	rep(i, n) rep(j, 8) {
		if (s[i] == tar[j]) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
		dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j+1]) % mod;
	}
	cout << dp[n][8] << endl;
	return 0;
}
