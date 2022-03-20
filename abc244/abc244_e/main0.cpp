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
	int n, m, k, s, t, x;
	cin >> n >> m >> k >> s >> t >> x;
	--s; --t; --x;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k+1, vector<ll>(2)));
	dp[s][0][0] = 1;
	rep(i, k) rep(j, n) rep(j2, 2) {
		for (int ti : g[j]) {
			if (ti == x) {
				dp[ti][i+1][(j2+1)%2] = (dp[ti][i+1][(j2+1)%2] + dp[j][i][j2]) % mod;
			}
			else {
				dp[ti][i+1][j2] = (dp[ti][i+1][j2] + dp[j][i][j2]) % mod;
			}
		}
	}
	cout << dp[t][k][0] << endl;
	return 0;
}
