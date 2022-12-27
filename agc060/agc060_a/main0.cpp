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
	string s;
	cin >> n >> s;
	vector<vector<ll>> dp(n+1, vector<ll>(27*27));
	dp[0][26*27+26] = 1;
	rep(i, n) rep(j, 26) {
		if (s[i]!='?' && s[i]!=(char)(j+'a')) continue;
		if (i == 0) dp[i+1][26*27+j] = (dp[i+1][26*27+j] + dp[i][26*27+26]) % mod;
		else if (i == 1) { rep(j2, 26) if (j2 != j) dp[i+1][j2*27+j] = (dp[i+1][j2*27+j] + dp[i][26*27+j2]) % mod; }
		else { rep(j1, 26) if (j1 != j) rep(j2, 26) if (j2 != j) dp[i+1][j1*27+j] = (dp[i+1][j1*27+j] + dp[i][j2*27+j1]) % mod; }
	}
	ll res = 0;
	rep(i, 27*27) res = (res + dp[n][i]) % mod;
	cout << res << endl;
	return 0;
}
