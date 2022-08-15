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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> dp(n+1, INF);
	vector<int> res(n, -1);
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		int pid = lower_bound(all(dp), a[vi]) - dp.begin(), pval = dp[pid];
		dp[pid] = a[vi];
		res[vi] = lower_bound(all(dp), INF) - dp.begin();
		for (int ti : g[vi]) if (ti != pi) dfs(dfs, ti, vi);
		dp[pid] = pval;
	};
	dfs(dfs);
	rep(i, n) cout << res[i] << endl;
	return 0;
}
