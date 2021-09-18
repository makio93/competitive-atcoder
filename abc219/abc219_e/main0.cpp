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

const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int main() {
	vector<vector<int>> a(4, vector<int>(4));
	rep(i, 4) rep(j, 4) cin >> a[i][j];
	int res = 0;
	rep3(i, 1, (1<<16)) {
		vector<vector<int>> b(4, vector<int>(4, -2));
		rep(j, 16) if ((i>>j)&1) b[j/4][j%4] = 0;
		bool ok1 = true;
		rep(j1, 4) rep(j2, 4) if (b[j1][j2]==-2 && a[j1][j2]==1) ok1 = false;
		if (!ok1) continue;
		int rcnt = 0;
		queue<pair<int, int>> que;
		rep(j1, 4) rep(j2, 4) if (b[j1][j2] == -2) {
			bool ext = false;
			que.emplace(j1, j2);
			b[j1][j2] = -1;
			while (!que.empty()) {
				auto pi = que.front(); que.pop();
				int y = pi.first, x = pi.second;
				rep(i2, 4) {
					int ny = y + dy[i2], nx = x + dx[i2];
					if (ny<0 || ny>=4 || nx<0 || nx>=4) {
						ext = true;
						continue;
					}
					if (b[ny][nx] != -2) continue;
					que.emplace(ny, nx);
					b[ny][nx] = -1;
				}
			}
			if (!ext) ++rcnt;
		}
		if (rcnt > 0) continue;
		int bcnt = 0;
		rep(j1, 4) rep(j2, 4) if (b[j1][j2] == 0) {
			++bcnt;
			que.emplace(j1, j2);
			b[j1][j2] = 1;
			while (!que.empty()) {
				auto pi = que.front(); que.pop();
				int y = pi.first, x = pi.second;
				rep(i2, 4) {
					int ny = y + dy[i2], nx = x + dx[i2];
					if (ny<0 || ny>=4 || nx<0 || nx>=4) continue;
					if (b[ny][nx] != 0) continue;
					que.emplace(ny, nx);
					b[ny][nx] = 1;
				}
			}
		}
		if (bcnt == 1) ++res;
	}
	cout << res << endl;
	return 0;
}
