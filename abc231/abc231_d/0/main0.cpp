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

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	bool ok = true;
	rep(i, n) if ((int)(g[i].size()) > 2) ok = false;
	vector<bool> visited(n), finished(n);
	rep(i, n) if (!finished[i]) {
		function<void(int,int)> dfs = [&](int v, int p) -> void {
			if (visited[v]) {
				ok = false;
				return;
			}
			visited[v] = true;
			for (int ti : g[v]) if (ti!=p && !finished[ti]) dfs(ti, v);
			visited[v] = false;
			finished[v] = true;
			return;
		};
		dfs(i, -1);
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
