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
const vector<int> dy = { -1, 0, 1, 0, }, dx = { 0, 1, 0, -1 };

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> dist(h, vector<int>(w, INF));
	queue<pair<int, int>> que;
	dist[0][0] = 1;
	que.emplace(0, 0);
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int y = pi.first, x = pi.second, di = dist[y][x], ndi = di + 1;
		rep(ii, 4) {
			int ny = y + dy[ii], nx = x + dx[ii];
			if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]!=INF) continue;
			dist[ny][nx] = ndi;
			que.emplace(ny, nx);
		}
	}
	if (dist[h-1][w-1] == INF) cout << -1 << endl;
	else {
		int wcnt = 0;
		rep(i, h) wcnt += count(all(s[i]), '.');
		cout << (wcnt-dist[h-1][w-1]) << endl;
	}
	return 0;
}
