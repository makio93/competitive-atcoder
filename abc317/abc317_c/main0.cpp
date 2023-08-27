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
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		--ai; --bi;
		g[ai].emplace_back(bi, ci);
		g[bi].emplace_back(ai, ci);
	}
	int res = 0;
	vector<bool> visited(n);
	function<void(int, int)> dfs = [&](int vi, int di) {
		res = max(res, di);
		visited[vi] = true;
		for (const auto [ti, tdi] : g[vi]) if (!visited[ti]) dfs(ti, di+tdi);
		visited[vi] = false;
	};
	rep(i, n) dfs(i, 0);
	cout << res << endl;
	return 0;
}
