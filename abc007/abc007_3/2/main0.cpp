// 学習2回目,自力AC

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
	int r, c, sy, sx, gy, gx;
	cin >> r >> c >> sy >> sx >> gy >> gx;
	vector<vector<char>> mat(r+2, vector<char>(c+2, '#'));
	rep(i, r) {
		string ci;
		cin >> ci;
		rep(j, c) mat[i+1][j+1] = ci[j];
	}
	vector<vector<int>> dist(r+2, vector<int>(c+2, INF));
	queue<pair<int, int>> que;
	dist[sy][sx] = 0;
	que.emplace(sy, sx);
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int yi = pi.first, xi = pi.second, di = dist[yi][xi], ndi = di + 1;
		const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
		rep(i1, 4) {
			int ny = yi + dy[i1], nx = xi + dx[i1];
			if (mat[ny][nx]!='.' || dist[ny][nx]!=INF) continue;
			dist[ny][nx] = ndi;
			que.emplace(ny, nx);
		}
	}
	cout << dist[gy][gx] << endl;
	return 0;
}
