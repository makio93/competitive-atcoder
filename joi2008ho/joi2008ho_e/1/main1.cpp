// 解説を見てから実装

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

int compress(vector<int>& x1, vector<int>& x2, int w) {
	int n1 = x1.size();
	set<int> st;
	st.insert(0);
	st.insert(w);
	for (int xi : x1) st.insert(xi);
	for (int xi : x2) st.insert(xi);
	vector<int> arr;
	for (auto itr=st.begin(); itr!=st.end(); ++itr) { arr.push_back(*itr); }
	rep(i, n1) x1[i] = lower_bound(all(arr), x1[i]) - arr.begin();
	rep(i, n1) x2[i] = lower_bound(all(arr), x2[i]) - arr.begin();
	return (int)(arr.size())-1;
}

const int INF = 1e9;

int main() {
	int w, h, n;
	cin >> w >> h >> n;
	vector<int> x1(n), y1(n), x2(n), y2(n);
	rep(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	int xmax = compress(x1, x2, w);
	int ymax = compress(y1, y2, h);
	vector<vector<int>> board(ymax, vector<int>(xmax, 0)), dist(ymax, vector<int>(xmax, INF));
	rep(i1, n) rep3(j, y1[i1], y2[i1]) {
			board[j][x1[i1]]++;
			board[j][x2[i1]]--;
	}
	rep(i, ymax) rep3(j, 1, xmax+1) board[i][j] += board[i][j-1];
	int res = 0;
	rep(i, ymax) rep(j, xmax) if (board[i][j]==0 && dist[i][j]==INF) {
		++res;
		queue<pair<int, int>> que;
		que.emplace(i, j);
		dist[i][j] = 0;
		while (!que.empty()) {
			auto p = que.front(); que.pop();
			int y = p.first, x = p.second, d = dist[y][x], nd = d + 1;
			const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
			rep(i2, 4) {
				int ny = y + dy[i2], nx = x + dx[i2];
				if (ny<0 || ny>=ymax || nx<0 || nx>=xmax) continue;
				if (board[ny][nx] != 0) continue;
				if (dist[ny][nx] <= nd) continue;
				que.emplace(ny, nx);
				dist[ny][nx] = nd;
			}
		}
	}
	cout << res << endl;
	return 0;
}
