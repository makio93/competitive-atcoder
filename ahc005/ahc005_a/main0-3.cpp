// AHC005:本番3

#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;
using iis = tuple<int, int, set<int>>;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int n;
vector<string> c;
vector<set<int>> memo;
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
set<int> gaze(int v) {
	if (!memo[v].empty()) return memo[v];
	int y = v / n, x = v % n;
	rep(i2, 4) {
		int ny = y, nx = x;
		while (ny>=0&&ny<n&&nx>=0&&nx<n&&c[ny][nx]!='#') {
			memo[v].insert(ny*n+nx);
			ny += dy[i2]; nx += dx[i2];
		}
	}
	return memo[v];
}

int main() {
	int si, sj;
	cin >> n >> si >> sj;
	c = vector<string>(n);
	rep(i, n) cin >> c[i];
	int rcnt = 0;
	rep(i, n) rep(j, n) if (c[i][j] != '#') ++rcnt;
	vector<map<int, int>> dist(n*n);
	vector<map<set<int>, string>> path(n*n);
	memo = vector<set<int>>(n*n);
	priority_queue<iis, vector<iis>, greater<iis>> que;
	que.emplace(0, si*n+sj, gaze(si*n+sj));
	dist[si*n+sj][(int)(gaze(si*n+sj).size())] = 0;
	path[si*n+sj][gaze(si*n+sj)] = string("");
	string res;
	while (!que.empty()) {
		auto [d, v, st] = que.top(); que.pop();
		string p = path[v][st];
		int y = v / n, x = v % n;
		rep(i2, 4) {
			int ny = y + dy[i2], nx = x + dx[i2];
			if (ny<0 || ny>=n || nx<0 || nx>=n || c[ny][nx]=='#') continue;
			int nd = d + (c[ny][nx] - '0');
			auto nst = gaze(ny*n+nx);
			bool ok = false;
			for (int vi : st) if (nst.insert(vi).second) ok = true;
			if (!ok) continue;
			if (dist[ny*n+nx].find((int)(nst.size()))!=dist[ny*n+nx].end()&&dist[ny*n+nx][(int)(nst.size())]<=nd) continue;
			que.emplace(nd, ny*n+nx, nst);
			dist[ny*n+nx][(int)(nst.size())] = nd;
			const string pchar = "URDL";
			path[ny*n+nx][nst] = (string)(p + pchar[i2]);
			if ((int)(nst.size()) >= rcnt) {
				res = path[ny*n+nx][nst];
				break;
			}
		}
		if (!res.empty()) break;
	}
	if (!res.empty()) {
		cout << res << endl;
		return 0;
	}
	int nlen = 0;
	for (auto p : path[si*n+sj]) if ((int)(p.first.size()) > nlen) {
		res = p.second;
		nlen = p.first.size();
	}
	cout << res << endl;
	return 0;
}
