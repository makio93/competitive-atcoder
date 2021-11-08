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

// 本番終了後,自力AC

const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].insert(vi);
		g[vi].insert(ui);
	}
	vector<bool> visited(n);
	queue<int> que;
	bool ok = true;
	rep(i, n) if ((int)(g[i].size()) == 1) {
		que.push(i);
		visited[i] = true;
	}
	while (!que.empty()) {
		int v = que.front(); que.pop();
		if (g[v].empty()) {
			ok = false;
			break;
		}
		int to = *g[v].begin();
		g[v].erase(to);
		g[to].erase(v);
		if ((int)(g[to].size()) == 1) {
			que.push(to);
			visited[to] = true;
		}
	}
	ll res = 0;
	rep(i, n) if (!visited[i] && (int)(g[i].size())!=2) ok = false;
	if (ok) {
		res = 1;
		function<void(int,int)> dfs = [&](int v, int p) -> void {
			visited[v] = true;
			for (int to : g[v]) if (to!=p && !visited[to]) dfs(to, v);
		};
		rep(i, n) if (!visited[i]) {
			dfs(i, -1);
			res = res * 2 % mod;
		}
	}
	cout << res << endl;
	return 0;
}
