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

// 本番AC

const int INF = (int)(1e9);

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, INF)));
	dp[0][0][0] = 0;
	rep(i, n) rep(j1, x+1) rep(j2, y+1) if (dp[i][j1][j2] != INF) {
		dp[i+1][j1][j2] = min(dp[i+1][j1][j2], dp[i][j1][j2]);
		dp[i+1][min(x,j1+a[i])][min(y,j2+b[i])] = min(dp[i+1][min(x,j1+a[i])][min(y,j2+b[i])], dp[i][j1][j2]+1);
	}
	if (dp[n][x][y] == INF) cout << -1 << endl;
	else cout << dp[n][x][y] << endl;
	return 0;
}
