// 練習0,自力AC

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
	int w, h;
	cin >> w >> h;
	vector<vector<bool>> build(h+2, vector<bool>(w+2));
	rep(i, h) rep(j, w) {
		int val;
		cin >> val;
		if (val == 1) build[i+1][j+1] = true;
	}
	const vector<vector<int>> di = { { -1, -1, 0, 1, 1, 0 }, { -1, -1, 0, 1, 1, 0 } };
	const vector<vector<int>> dj = { { -1, 0, 1, 0, -1, -1 }, { 0, 1, 1, 1, 0, -1 } };
	vector<vector<bool>> visited(h+2, vector<bool>(w+2));
	set<pair<int, int>> walls;
	queue<pair<int, int>> que;
	rep(i, w+2) {
		que.emplace(0, i);
		que.emplace(h+1, i);
		visited[0][i] = visited[h+1][i] = true;
	}
	rep3(i, 1, h+1) {
		que.emplace(i, 0);
		que.emplace(i, w+1);
		visited[i][0] = visited[i][w+1] = true;
	}
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int vi = pi.first, vj = pi.second;
		rep(i, 6) {
			int ni = vi + di[vi%2][i], nj = vj + dj[vi%2][i];
			if (ni<0 || ni>=h+2 || nj<0 || nj>=w+2) continue;
			if (build[ni][nj]) walls.emplace(vi*(w+2)+vj, ni*(w+2)+nj);
			else if (!visited[ni][nj]) {
				visited[ni][nj] = true;
				que.emplace(ni, nj);
			}
		}
	}
	cout << (int)(walls.size()) << endl;
	return 0;
}
