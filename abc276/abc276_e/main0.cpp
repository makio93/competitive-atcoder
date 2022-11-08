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
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	int sy = -1, sx = -1;
	rep(i, h) {
		rep(j, w) if (c[i][j] == 'S') {
			sy = i; sx = j;
			break;
		}
		if (sy != -1) break;
	}
	vector<vector<bool>> visited(h, vector<bool>(w)), finished(h, vector<bool>(w));
	auto dfs = [&](auto dfs, int yi, int xi, int di=0) -> bool {
		if (c[yi][xi]=='S' && visited[yi][xi]) return (di >= 4);
		visited[yi][xi] = true;
		rep(i, 4) {
			int ny = yi + dy[i], nx = xi + dx[i], ndi = di + 1;
			if (ny<0 || ny>=h || nx<0 || nx>=w || finished[ny][nx] || c[ny][nx]=='#') continue;
			if (visited[ny][nx] && c[ny][nx]!='S') continue;
			if (dfs(dfs, ny, nx, ndi)) return true;
		}
		finished[yi][xi] = true;
		return false;
	};
	if (dfs(dfs, sy, sx)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
