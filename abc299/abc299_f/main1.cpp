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
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<int>> sig(n+1, vector<int>(26, INF));
	rep(i, n+1) rep(j, 26) {
		int id = i;
		while (id<n && s[id]-'a'!=j) ++id;
		if (id < n) sig[i][j] = id;
	}
	ll res = 0;
	rep(x, n) {
		vector<vector<ll>> dp(n, vector<ll>(n));
		if (sig[0][s[x]-'a'] == INF) continue;
		dp[sig[0][s[x]-'a']][x] = 1;
		rep(i, n) rep(j, n) rep(c, 26) {
			if (sig[i+1][c]==INF || sig[j+1][c]==INF) continue;
			dp[sig[i+1][c]][sig[j+1][c]] = (dp[sig[i+1][c]][sig[j+1][c]] + dp[i][j]) % mod;
		}
		rep(i, n) rep(j, n) if (sig[i+1][s[x]-'a'] == x) res = (res + dp[i][j]) % mod;
	}
	cout << res << endl;
	return 0;
}
