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

// 自力で解答、わからない

const ll mod = (ll)(1e9) + 7;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	vector<vector<vector<ll>>> dp(h+1, vector<vector<ll>>(w+1, vector<ll>(1<<4)));
	rep(i, w+1) dp[0][i][0] = 1;
	rep(i, h+1) dp[i][0][0] = 1;
	rep3(i, 1, h+1) rep3(j, 1, w+1) {
		rep(i2, (1<<4)) {
			vector<int> ids(4);
			rep(j2, 4) {
				if ((i2>>j2) & 1) ids[j2] = 1;
				else ids[j2] = 0;
			}
			int kcnt = 0;
			rep(j2, 4) if (ids[j2] == 1) ++kcnt;
			if (kcnt > 1) continue;
			const vector<int> dy = { -1, -1, 0, 0 }, dx = { -1, 0, -1, 0 };
			bool bok = true;
			rep(j2, 4) {
				int ny = i + dy[j2], nx = j + dx[j2];
				if (ids[j2] == 1) {
					if (ny<=0 || nx<=0) bok = false;
					else if (c[ny-1][nx-1] != '.') bok = false;
				}
				if (!bok) break;
			}
			if (!bok) continue;
			ll add = 0;
			rep(i3, (1<<4)) {
				vector<int> ids2(4);
				rep(j3, 4) {
					if ((i3>>j3) & 1) ids2[j3] = 1;
					else ids2[j3] = 0;
				}
				if (ids[0]==ids2[2] && ids[1]==ids2[3]) add = (add + dp[i-1][j][i3]) % mod;
				if (ids[0]==ids2[1] && ids[2]==ids2[3]) add = (add + dp[i][j-1][i3]) % mod;
				if (ids[0] == ids2[3]) add = (add + (mod - (dp[i-1][j-1][i3]))) % mod;
			}
			dp[i][j][i2] = (dp[i][j][i2] + add) % mod;
		}
	}
	ll res = 0;
	rep(i, (1<<4)) res = (res + dp[h][w][i]) % mod;
	cout << res << endl;
	return 0;
}
