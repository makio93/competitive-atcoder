// 学習1回目,自力AC

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

const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<vector<pair<int, int>>> g(n);
	rep(i, n-1) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		--ui; --vi;
		g[ui].emplace_back(vi, wi);
		g[vi].emplace_back(ui, wi);
	}
	vector<vector<ll>> dp(n, vector<ll>(2, -LINF));
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		vector<pair<ll, ll>> rlst;
		for (auto tpi : g[vi]) if (tpi.first != pi) {
			dfs(dfs, tpi.first, vi);
			rlst.emplace_back(dp[tpi.first][1], dp[tpi.first][0]+tpi.second);
		}
		if (d[vi]-1 >= 0) dp[vi][0] = dp[vi][1] = 0;
		else dp[vi][1] = 0;
		sort(all(rlst), [](pair<ll, ll> li, pair<ll, ll> ri) -> bool {
			return li.second - li.first > ri.second - ri.first;
		});
		int m = rlst.size();
		ll rval = 0;
		rep(i, m) rval += rlst[i].first;
		rep(i, m+1) {
			if (i <= d[vi]-1) dp[vi][0] = max(dp[vi][0], rval);
			if (i <= d[vi]) dp[vi][1] = max(dp[vi][1], rval);
			if (i<m && rlst[i].second<-LINF/10) break;
			if (i < m) rval += rlst[i].second - rlst[i].first;
		}
	};
	dfs(dfs);
	ll res = 0;
	rep(i, n) res = max(res, dp[i][1]);
	cout << res << endl;
	return 0;
}
