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

// 単純な貪欲法

vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
string itd = "URDL";
unordered_map<char, int> dti = { { 'U', 0 }, { 'R', 1 }, { 'D', 2 }, { 'L', 3 } };

int score(pair<int, int> s, vector<vector<int>>& t, vector<vector<int>>& p, string o) {
	int y = s.first, x = s.second, val = p[y][x];
	set<int> visited;
	visited.insert(t[y][x]);
	for (char nd : o) {
		int ndi = dti[nd];
		y += dy[ndi]; x += dx[ndi];
		if (y<0 || y>=50 || x<0 || x>=50) return 0;
		if (visited.find(t[y][x]) != visited.end()) return 0;
		val += p[y][x];
		visited.insert(t[y][x]);
	}
	return val;
}

int main() {
	int si, sj;
	cin >> si >> sj;
	vector<vector<int>> t(50, vector<int>(50)), p(50, vector<int>(50));
	rep(i, 50) rep(j, 50) cin >> t[i][j];
	rep(i, 50) rep(j, 50) cin >> p[i][j];
	string res = "";
	set<int> visited;
	int y = si, x = sj;
	visited.insert(t[y][x]);
	while (1) {
		pair<int, int> mval = { -1, -1 };
		rep(i, 4) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny<0 || ny>=50 || nx<0 || nx>=50) continue;
			int nt = t[ny][nx];
			if (visited.find(nt) != visited.end()) continue;
			mval = max(mval, { p[ny][nx], i });
		}
		if (mval.second == -1) break;
		res += itd[mval.second];
		y += dy[mval.second]; x += dx[mval.second];
		visited.insert(t[y][x]);
	}
	cout << res << endl;
	cout << score({si,sj}, t, p, res) << endl;
	return 0;
}
