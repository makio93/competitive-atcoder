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
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	if (m != n-1) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> deg(n);
	int cnt1 = 0, cnt2 = 0;
	rep(i, n) {
		if ((int)(g[i].size()) == 1) ++cnt1;
		else if ((int)(g[i].size()) == 2) ++cnt2;
	}
	if (cnt1!=2 || cnt2!=n-2) {
		cout << "No" << endl;
		return 0;
	}
	vector<bool> visited(n);
	auto dfs = [&](auto dfs, int vi) -> void {
		visited[vi] = true;
		for (const int& ti : g[vi]) if (!visited[ti]) dfs(dfs, ti);
	};
	int gcnt = 0;
	rep(i, n) if (!visited[i]) {
		dfs(dfs, i);
		++gcnt;
	}
	if (gcnt == 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
