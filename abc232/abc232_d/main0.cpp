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

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	vector<vector<bool>> dist(h, vector<bool>(w));
	queue<pair<int, int>> que;
	dist[0][0] = true;
	que.emplace(0, 0);
	while (!que.empty()) {
		auto [y, x] = que.front(); que.pop();
		const vector<int> dy = { 1, 0 }, dx = { 0, 1 };
		rep(i, 2) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny<0 || ny>=h || nx<0 || nx>=w || c[ny][nx]=='#' || dist[ny][nx]) continue;
			dist[ny][nx] = true;
			que.emplace(ny, nx);
		}
	}
	int res = 0;
	rep(i, h) rep(j, w) if (dist[i][j]) res = max(res, i+j+1);
	cout << res << endl;
	return 0;
}
