// 本番WA

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
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> p(n);
	iota(all(p), 0);
	vector<int> dep;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	rep(i, n) {
		dep.assign(n, -1);
		auto dfs = [&](auto dfs, int vi, int di=0) -> void {
			dep[vi] = di;
			if (dep[p[vi]] != -1) {
				if (!pq.empty() && dep[p[vi]]>pq.top().first) swap(p[vi], p[pq.top().second]);
				pq.emplace(di, vi);
			}
			for (const int& ti : g[vi]) if (dep[ti] == -1) dfs(dfs, ti, di+1);
			while (!pq.empty() && pq.top().first>=di) pq.pop();
		};
		dfs(dfs, i);
		while (!pq.empty()) pq.pop();
	}
	rep(i, n) cout << (p[i]+1) << (i<n-1?' ':'\n');
	return 0;
}
