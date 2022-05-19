// 学習1回目,解説AC

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
	int h, w, ch, cw, dh, dw;
	cin >> h >> w >> ch >> cw >> dh >> dw;
	--ch; --cw; --dh; --dw;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> dist(h, vector<int>(w, INF));
	deque<pair<int, int>> deq;
	dist[ch][cw] = 0;
	deq.emplace_back(ch, cw);
	while (!deq.empty()) {
		auto pi = deq.front(); deq.pop_front();
		int y = pi.first, x = pi.second, di = dist[y][x];
		rep(i1, 4) {
			int ny = y + dy[i1], nx = x + dx[i1];
			if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]<=di) continue;
			dist[ny][nx] = di;
			deq.emplace_front(ny, nx);
		}
		for (int dy2=-2; dy2<=2; ++dy2) for (int dx2=-2; dx2<=2; ++dx2) {
			int ny = y + dy2, nx = x + dx2, ndi = di + 1;
			if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]<=ndi) continue;
			dist[ny][nx] = ndi;
			deq.emplace_back(ny, nx);
		}
	}
	int res = dist[dh][dw];
	if (res == INF) res = -1;
	cout << res << endl;
	return 0;
}
