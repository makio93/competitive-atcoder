#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後、自力AC

const ll LINF = (ll)(1e18);

int main() {
	int h, w, c;
	cin >> h >> w >> c;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	const vector<int> dy = { 1, 1, -1, -1 }, dx = { 1, -1, 1, -1 };
	const vector<int> sy = { 0, 0, h-1, h-1 }, sx = { 0, w-1, 0, w-1 };
	const vector<int> gy = { h, h, -1, -1 }, gx = { w, -1, w, -1 };
	vector<vector<vector<ll>>> dp(4, vector<vector<ll>>(h, vector<ll>(w, LINF)));
	rep(i0, 4) {
		for (int y=sy[i0]; y!=gy[i0]; y+=dy[i0]) for (int x=sx[i0]; x!=gx[i0]; x+=dx[i0]) {
			int py = y - dy[i0], px = x - dx[i0];
			if (py>=0 && py<h) {
				if (dp[i0][py][x] < LINF) dp[i0][y][x] = min(dp[i0][y][x], dp[i0][py][x]+c);
				dp[i0][y][x] = min(dp[i0][y][x], (ll)a[py][x]+c);
			}
			if (px>=0 && px<w) {
				if (dp[i0][y][px] < LINF) dp[i0][y][x] = min(dp[i0][y][x], dp[i0][y][px]+c);
				dp[i0][y][x] = min(dp[i0][y][x], (ll)a[y][px]+c);
			}
		}
	}
	ll res = LINF;
	rep(i0, 4) rep(i, h) rep(j, w) if (dp[i0][i][j] < LINF) res = min(res, dp[i0][i][j]+a[i][j]);
	cout << res << endl;
	return 0;
}
