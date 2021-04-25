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

// ダイクストラ的な方針

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
	int m = 0;
	rep(i, 50) rep(j, 50) m = max(m, t[i][j]);
	vector<int> dist(m+1, -1);
	map<pair<int,int>, string> routes;
	priority_queue<pair<int, pair<pair<int,int>,set<int>>>> que;
	que.emplace(p[si][sj], make_pair(pair<int,int>({si,sj}),set<int>({t[si][sj]})));
	dist[t[si][sj]] = p[si][sj];
	routes[{si,sj}] = "";
	while (!que.empty()) {
		auto pi = que.top(); que.pop();
		int sval = pi.first, y = pi.second.first.first, x = pi.second.first.second;
		auto vi = pi.second.second;
		if (sval != dist[t[y][x]]) continue;
		string ri = routes[{y,x}];
		rep(i, 4) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny<0 || ny>=50 || nx<0 || nx>=50) continue;
			if (vi.find(t[ny][nx]) != vi.end()) continue;
			if (dist[t[ny][nx]] >= sval+p[ny][nx]) continue;
			vi.insert(t[ny][nx]);
			que.emplace(sval+p[ny][nx], make_pair(pair<int,int>({ny,nx}),vi));
			dist[t[ny][nx]] = sval+p[ny][nx];
			routes[{ny,nx}] = ri + itd[i];
			vi.erase(t[ny][nx]);
		}
	}
	pair<int, int> rpos = { -1, -1 };
	rep(i, m+1) rpos = max(rpos, { dist[i], i });
	int tval = rpos.second;
	vector<pair<int,int>> pos;
	rep(i, 50) rep(j, 50) if (t[i][j] == tval) pos.emplace_back(i, j);
	pair<int, string> res = { -1, "" };
	for (auto pi : pos) {
		res = max(res, { score({si,sj}, t, p, routes[pi]), routes[pi] });
	}
	//cout << res.first << endl;
	cout << res.second << endl;
	return 0;
}
