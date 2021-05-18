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
	int h, w, rs, cs, rt, ct;
	cin >> h >> w >> rs >> cs >> rt >> ct;
	--rs; --cs; --rt; --ct;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	vector<vector<pair<int, int>>> dist(h, vector<pair<int, int>>(w, { INF, 0 }));
	queue<pair<int, int>> que;
	que.emplace(rs, cs);
	dist[rs][cs] = { 0, (1<<4)-1 };
	while (!que.empty()) {
		auto v = que.front(); que.pop();
		int y = v.first, x = v.second;
		int d = dist[y][x].first, r = dist[y][x].second;
		const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
		rep(i1, 4) {
			int ny = y + dy[i1], nx = x + dx[i1];
			if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
			if (c[ny][nx] == '#') continue;
			int nd = d + (((r>>i1)&1) ? 0 : 1);
			if (nd > dist[ny][nx].first) continue;
			if (nd == dist[ny][nx].first) {
				if ((dist[ny][nx].second>>i1) & 1) continue;
				dist[ny][nx].second |= (1<<i1);
			}
			else dist[ny][nx] = { nd, (1<<i1) };
			que.emplace(ny, nx);
		}
	}
	cout << dist[rt][ct].first << endl;
	return 0;
}
