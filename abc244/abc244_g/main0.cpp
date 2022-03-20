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
	dsu ds(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		if (ds.same(ui, vi)) continue;
		ds.merge(ui, vi);
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	string s;
	cin >> s;
	vector<int> dist(n);
	vector<int> res;
	auto dfs = [&](auto& dfs, int vi, int pi) -> void {
		dist[vi] = (dist[vi] + 1) % 2;
		res.push_back(vi+1);
		for (int ti : g[vi]) if (ti != pi) {
			dfs(dfs, ti, vi);
			dist[vi] = (dist[vi] + 1) % 2;
			res.push_back(vi+1);
			if (dist[ti] != s[ti]-'0') {
				dist[ti] = (dist[ti] + 1) % 2;
				dist[vi] = (dist[vi] + 1) % 2;
				res.push_back(ti+1);
				res.push_back(vi+1);
			}
		}
	};
	dfs(dfs, 0, -1);
	if (dist[0] != s[0]-'0') {
		reverse(all(res));
		res.pop_back();
		reverse(all(res));
	}
	int k = res.size();
	cout << k << endl;
	if (k == 0) cout << endl;
	else rep(i, k) printf("%d%c", res[i], (i<k-1?' ':'\n'));
	return 0;
}
