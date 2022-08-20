// 学習1回目,解説AC

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
	vector<vector<ll>> dp(n, vector<ll>(2));
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		vector<ll> slst;
		for (auto tpi : g[vi]) if (tpi.first != pi) {
			dfs(dfs, tpi.first, vi);
			dp[vi][0] += dp[tpi.first][1], dp[vi][1] += dp[tpi.first][1];
			slst.push_back((dp[tpi.first][0]+tpi.second)-dp[tpi.first][1]);
		}
		sort(slst.rbegin(), slst.rend());
		int slen = slst.size();
		rep(i, slen) {
			if (slst[i] <= 0) break;
			if (i < d[vi]-1) dp[vi][0] += slst[i];
			if (i < d[vi]) dp[vi][1] += slst[i];
		}
		if (d[vi]-1 < 0) dp[vi][0] = -LINF;
	};
	dfs(dfs);
	cout << dp[0][1] << endl;
	return 0;
}
