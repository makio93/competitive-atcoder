// 学習1回目,自力AC

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
	int h, w, ch, cw, dh, dw;
	cin >> h >> w >> ch >> cw >> dh >> dw;
	--ch; --cw; --dh; --dw;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> dist(h, vector<int>(w, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	dist[ch][cw] = 0;
	pq.emplace(0, make_pair(ch, cw));
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int di = pi.first, y = pi.second.first, x = pi.second.second;
		if (dist[y][x] != di) continue;
		vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
		rep(i, 4) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]<=di) continue;
			dist[ny][nx] = di;
			pq.emplace(di, make_pair(ny, nx));
		}
		for (int i=-2; i<=2; ++i) for (int j=-2; j<=2; ++j) {
			int ny = y + i, nx = x + j, ndi = di + 1;
			if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]<=ndi) continue;
			dist[ny][nx] = ndi;
			pq.emplace(ndi, make_pair(ny, nx));
		}
	}
	if (dist[dh][dw] == INF) cout << -1 << endl;
	else cout << dist[dh][dw] << endl;
	return 0;
}
