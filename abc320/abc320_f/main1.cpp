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
	int n, h;
	cin >> n >> h;
	vector<int> x(n+1), p(n+1), f(n+1);
	rep3(i, 1, n+1) cin >> x[i];
	rep3(i, 1, n) cin >> p[i] >> f[i];
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(h+1, vector<int>(h+1, INF)));
	rep(i, h+1) dp[0][h][i] = 0;
	rep3(i, 1, n+1) {
		int di = x[i] - x[i-1];
		rep(j1, h+1) rep(j2, h+1) {
			int li = j1 + di, ri = j2 - di;
			if (li <= h && ri >= 0) dp[i][j1][j2] = min(dp[i][j1][j2], dp[i-1][li][ri]);
			if (j1 < h) {
				li = j1 - f[i] + di;
				if (j1-f[i] >= 0 && li <= h && ri >= 0) dp[i][j1][j2] = min(dp[i][j1][j2], dp[i-1][li][ri] + p[i]);
			}
			else {
				rep3(ti, j1-f[i], h+1) {
					li = ti + di;
					if (li <= h && ri >= 0) dp[i][j1][j2] = min(dp[i][j1][j2], dp[i-1][li][ri] + p[i]);
				}
			}
			li = j1 + di, ri = min(h, j2+f[i]) - di;
			if (li <= h && ri >= 0) dp[i][j1][j2] = min(dp[i][j1][j2], dp[i-1][li][ri] + p[i]);
		}
	}
	int res = INF;
	rep(i, h+1) res = min(res, dp[n][i][i]);
	if (res == INF) res = -1;
	cout << res << endl;
	return 0;
}
