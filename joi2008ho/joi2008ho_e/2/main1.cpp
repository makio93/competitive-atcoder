// 学習2回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int w, h, n;
	cin >> w >> h >> n;
	vector<int> x1(n), y1(n), x2(n), y2(n);
	rep(i, n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	function<int(vector<int>&,vector<int>&,int)> compress = [](vector<int>& x1, vector<int>& x2, int w) -> int {
		vector<int> xlst;
		xlst.push_back(0);
		xlst.push_back(w);
		for (int xi : x1) xlst.push_back(xi);
		for (int xi : x2) xlst.push_back(xi);
		sort(all(xlst));
		xlst.erase(unique(all(xlst)), xlst.end());
		for (int& xi : x1) xi = distance(xlst.begin(), find(all(xlst), xi));
		for (int& xi : x2) xi = distance(xlst.begin(), find(all(xlst), xi));
		return xlst.size() - 1;
	};
	w = compress(x1, x2, w);
	h = compress(y1, y2, h);
	vector<vector<int>> sub(h, vector<int>(w+1));
	rep(i, n) rep3(j, y1[i], y2[i]) {
		sub[j][x1[i]]++;
		sub[j][x2[i]]--;
	}
	rep(i, h) rep(j, w) sub[i][j+1] += sub[i][j];
	int res = 0;
	rep(i, h) rep(j, w) if (sub[i][j] == 0) {
		++res;
		queue<pair<int, int>> que;
		sub[i][j] = res;
		que.emplace(i, j);
		while (!que.empty()) {
			auto pi = que.front(); que.pop();
			int y = pi.first, x = pi.second;
			const vector<int> dy = { 1, 0, -1, 0 }, dx = { 0, 1, 0, -1 };
			rep(i2, 4) {
				int ny = y + dy[i2], nx = x + dx[i2];
				if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
				if (sub[ny][nx] != 0) continue;
				sub[ny][nx] = res;
				que.emplace(ny, nx);
			}
		}
	}
	cout << res << endl;
	return 0;
}
