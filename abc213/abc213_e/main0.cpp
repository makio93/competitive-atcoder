#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;
using pii = pair<int, int>;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const int INF = (int)(1e9);

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> dist(h, vector<int>(w, INF));
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> que;
	que.emplace(0, make_pair(0, 0));
	dist[0][0] = 0;
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		int d = p.first, y = p.second.first, x = p.second.second;
		if (dist[y][x] != d) continue;
		vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
		rep(i2, 4) {
			int ny = y + dy[i2], nx = x + dx[i2];
			if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
			if (s[ny][nx] == '#') continue;
			if (dist[ny][nx] <= d) continue;
			que.emplace(d, make_pair(ny, nx));
			dist[ny][nx] = d;
		}
		for (int i2=-2; i2<=2; ++i2) for (int j2=-2; j2<=2; ++j2) {
			if (abs(i2)==2 && abs(j2)==2) continue;
			if (i2==0 && j2==0) continue;
			int ny = y + i2, nx = x + j2;
			if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
			if (s[ny][nx] != '#') continue;
			if (dist[ny][nx] <= d+1) continue;
			que.emplace(d+1, make_pair(ny, nx));
			dist[ny][nx] = d+1;
		}
	}
	cout << dist[h-1][w-1] << endl;
	return 0;
}
