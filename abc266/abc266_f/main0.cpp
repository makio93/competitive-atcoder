// 本番AC

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
	int n, q;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<bool> finished(n), visited(n);
	unordered_set<int> rlst;
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> int {
		visited[vi] = true;
		for (int ti : g[vi]) if (ti != pi) {
			if (finished[ti]) continue;
			if (visited[ti]) {
				rlst.insert(vi);
				return ti;
			}
			int rval = dfs(dfs, ti, vi);
			if (rval != -1) {
				rlst.insert(vi);
				if (rval != vi) return rval;
				else return -1;
			}
		}
		finished[vi] = true;
		return -1;
	};
	dfs(dfs);
	vector<bool> searched(n);
	vector<int> gids(n, -1);
	for (const int& pi : rlst) {
		queue<int> que;
		searched[pi] = true;
		gids[pi] = pi;
		que.push(pi);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			for (int ti : g[vi]) {
				if (rlst.find(ti)!=rlst.end() || searched[ti]) continue;
				searched[ti] = true;
				gids[ti] = pi;
				que.push(ti);
			}
		}
	}
	cin >> q;
	rep(i, q) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		if (gids[xi] == gids[yi]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
