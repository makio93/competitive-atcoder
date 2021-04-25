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

// ダイクストラ的な方針にさらにムダ足をしようとしてみた？

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
	set<int> visited;
	int ty = si, tx = sj, ty2 = ty, tx2 = tx;
	ty2 += dy[dti[res.second.front()]]; tx2 += dx[dti[res.second.front()]];
	for (char c : res.second) {
		ty += dy[dti[c]]; tx += dx[dti[c]];
		visited.insert(t[ty][tx]);
	}
	priority_queue<pair<int, pair<pair<int,int>,set<int>>>> que2;
	que2.emplace(p[si][sj], make_pair(pair<int,int>({si,sj}),set<int>({t[si][sj]})));
	vector<int> dist2(m+1, -1);
	map<pair<int,int>, string> routes2;
	dist2[t[si][sj]] = p[si][sj];
	routes2[{si,sj}] = "";
	while (!que2.empty()) {
		auto pi = que2.top(); que2.pop();
		int sval = pi.first, y = pi.second.first.first, x = pi.second.first.second;
		auto vi = pi.second.second;
		if (sval != dist2[t[y][x]]) continue;
		string ri = routes2[{y,x}];
		rep(i, 4) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny<0 || ny>=50 || nx<0 || nx>=50) continue;
			if (visited.find(t[ny][nx]) != visited.end()) continue;
			if (vi.find(t[ny][nx]) != vi.end()) continue;
			if (dist2[t[ny][nx]] > sval+p[ny][nx]) continue;
			vi.insert(t[ny][nx]);
			que2.emplace(sval+p[ny][nx], make_pair(pair<int,int>({ny,nx}),vi));
			dist2[t[ny][nx]] = sval+p[ny][nx];
			routes2[{ny,nx}] = ri + itd[i];
			vi.erase(t[ny][nx]);
		}
	}
	pair<int, pair<string, int>> res2 = { -1, { "", -1 } };
	rep(i, 4) {
		int ty3 = ty2 + dy[i], tx3 = tx2 + dx[i];
		if (routes2.find({ty3,tx3}) == routes2.end()) continue;
		res2 = max(res2, { score({si,sj}, t, p, routes2[{ty3,tx3}]), { routes2[{ty3,tx3}], i } });
	}
	if (res2.first != -1) {
		int rid = (res2.second.second + 2) % 4;
		string rstr = res2.second.first + (char)(itd[rid]) + res.second.substr(1);
		//cout << score({si,sj}, t, p, rstr) << endl;
		cout << rstr << endl;
		//cout << (int)(res2.first) << endl;
	}
	else {
		//cout << res.first << endl;
		cout << res.second << endl;
	}
	return 0;
}
