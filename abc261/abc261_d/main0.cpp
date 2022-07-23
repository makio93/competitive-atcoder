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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	unordered_map<int, int> ctoy;
	rep(i, m) {
		int ci, yi;
		cin >> ci >> yi;
		ctoy[ci] = yi;
	}
	vector<vector<ll>> dp(n+1, vector<ll>(n+1, -INF));
	dp[0][0] = 0;
	rep(i, n) rep(j, n) if (dp[i][j] != -INF) {
		dp[i+1][0] = max(dp[i+1][0], dp[i][j]);
		ll aval = (ctoy.find(j+1)!=ctoy.end() ? ctoy[j+1] : 0);
		dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+x[i]+aval);
	}
	ll res = 0;
	rep(i, n+1) res = max(res, dp[n][i]);
	cout << res << endl;
	return 0;
}
