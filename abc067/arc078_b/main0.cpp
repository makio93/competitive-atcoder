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
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> col(n);
	vector<int> path;
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> bool {
		if (vi == n-1) return true;
		for (int ti : g[vi]) if (ti != pi) {
			path.push_back(ti);
			if (dfs(dfs, ti, vi)) return true;
			path.pop_back();
		}
		return false;
	};
	path.push_back(0);
	dfs(dfs);
	int plen = path.size(), hlen = (plen+1) / 2;
	rep(i, plen) {
		if (i < hlen) col[path[i]] = 1;
		else col[path[i]] = -1;
	}
	queue<int> que;
	rep(i, n) if (col[i] != 0) que.push(i);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int ci = col[vi];
		for (int ti : g[vi]) if (col[ti] == 0) {
			col[ti] = ci;
			que.push(ti);
		}
	}
	int ccnt = 0;
	rep(i, n) if (col[i] == 1) ++ccnt;
	if (ccnt > n-ccnt) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
	return 0;
}
