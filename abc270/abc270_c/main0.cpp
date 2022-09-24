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
	int n, x, y;
	cin >> n >> x >> y;
	--x; --y;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> res;
	auto dfs = [&](auto dfs, int vi, int pi=-1) -> bool {
		if (vi == y) return true;
		for (int& ti : g[vi]) if (ti != pi) {
			res.push_back(ti+1);
			if (dfs(dfs, ti, vi)) return true;
			res.pop_back();
		}
		return false;
	};
	res.push_back(x+1);
	dfs(dfs, x);
	int rlen = res.size();
	rep(i, rlen) cout << res[i] << (i<rlen-1?' ':'\n');
	return 0;
}
