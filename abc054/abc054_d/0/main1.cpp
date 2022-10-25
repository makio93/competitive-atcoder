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

int main() {
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	int asum = 0, bsum = 0;
	rep(i, n) asum += a[i];
	rep(i, n) bsum += b[i];
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(asum+1, vector<int>(bsum+1, INF)));
	dp[0][0][0] = 0;
	rep(i, n) rep(j1, asum+1) rep(j2, bsum+1) if (dp[i][j1][j2] != INF) {
		dp[i+1][j1][j2] = min(dp[i+1][j1][j2], dp[i][j1][j2]);
		dp[i+1][j1+a[i]][j2+b[i]] = min(dp[i+1][j1+a[i]][j2+b[i]], dp[i][j1][j2]+c[i]);
	}
	int res = INF;
	rep3(i, 1, asum+1) rep3(j, 1, bsum+1) if (i*mb == j*ma) res = min(res, dp[n][i][j]);
	if (res == INF) res = -1;
	cout << res << endl;
	return 0;
}
