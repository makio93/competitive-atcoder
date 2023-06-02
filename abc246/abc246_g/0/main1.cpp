// 解説AC

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

const int INF = (int)(1e9) + 5;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep3(i, 1, n) cin >> a[i];
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	int lval = 0, rval = INF;
	vector<int> dp(n);
	while (rval-lval > 1) {
		int cval = lval + (rval-lval) / 2;
		auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
			dp[vi] = 0;
			for (const int& ti : g[vi]) if (ti != pi) {
				dfs(dfs, ti, vi);
				dp[vi] += dp[ti];
			}
			dp[vi] = max(0, dp[vi]-1) + (a[vi]>=cval ? 1 : 0);
		};
		dfs(dfs);
		if (dp[0] == 0) rval = cval;
		else lval = cval;
	}
	cout << lval << endl;
	return 0;
}
