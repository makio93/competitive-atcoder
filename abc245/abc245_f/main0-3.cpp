// 終了後,自力1,AC

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
	int n, m;
	cin >> n >> m;
	scc_graph sg(n);
	vector<vector<int>> rg(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		sg.add_edge(ui, vi);
		rg[vi].push_back(ui);
	}
	auto slst = sg.scc();
	vector<bool> visited(n);
	auto dfs = [&](auto dfs, int vi) -> void {
		visited[vi] = true;
		for (int ti : rg[vi]) if (!visited[ti]) dfs(dfs, ti);
	};
	rep(i, (int)(slst.size())) if ((int)(slst[i].size()) > 1) {
		rep(j, (int)(slst[i].size())) if (!visited[slst[i][j]]) dfs(dfs, slst[i][j]);
	}
	int res = 0;
	rep(i, n) if (visited[i]) ++res;
	cout << res << endl;
	return 0;
}
