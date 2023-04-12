// 自力AC

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
	int n, u, v;
	cin >> n >> u >> v;
	--u; --v;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> par(n, -1), dep(n), mdep(n);
	auto dfs1 = [&](auto dfs1, int vi, int pi=-1, int di=0) -> void {
		par[vi] = pi;
		dep[vi] = mdep[vi] = di;
		for (int ti : g[vi]) if (ti != pi) {
			dfs1(dfs1, ti, vi, di+1);
			mdep[vi] = max(mdep[vi], mdep[ti]);
		}
	};
	dfs1(dfs1, v);
	int mval = 0, vi = u;
	while (dep[u]-dep[vi] < dep[vi]-dep[v]) {
		mval = max(mval, mdep[vi]-dep[v]-1);
		vi = par[vi];
	}
	cout << mval << endl;
	return 0;
}
