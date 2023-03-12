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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n*2);
	rep(i, m) {
		int ai, ci;
		char bi, di;
		cin >> ai >> bi >> ci >> di;
		--ai; --ci;
		int ui = ai + (bi == 'R' ? 0 : n), vi = ci + (di == 'R' ? 0 : n);
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	rep(i, n) {
		g[i].push_back(i+n);
		g[i+n].push_back(i);
	}
	int x = 0, y = 0;
	vector<bool> visited(n*2);
	rep(i, n*2) if (!visited[i]) {
		auto dfs = [&](auto dfs, int vi, int pi=-1) -> bool {
			visited[vi] = true;
			bool rval = false;
			for (const int& ti : g[vi]) if (ti != pi) {
				if (visited[ti] || dfs(dfs, ti, vi)) rval = true;
			}
			return rval;
		};
		if (dfs(dfs, i)) ++x;
		else ++y;
	}
	cout << x << ' ' << y << endl;
	return 0;
}
