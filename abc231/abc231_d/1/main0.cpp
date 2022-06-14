// 

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
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	rep(i, n) if ((int)(g[i].size()) > 2) {
		cout << "No" << endl;
		return 0;
	}
	vector<bool> visited(n);
	auto dfs = [&](auto dfs, int vi, int pi=-1) -> bool {
		visited[vi] = true;
		for (int ti : g[vi]) if (pi != ti) {
			if (visited[ti]) return false;
			if (!dfs(dfs, ti, vi)) return false;
		}
		return true;
	};
	bool res = true;
	rep(i, n) if (!visited[i]) {
		if (!dfs(dfs, i)) {
			res = false;
			break;
		}
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
