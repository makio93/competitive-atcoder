// 本番,TLE

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

const double DINF = 1e18;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, pair<int, int>>>> g(n);
	rep(i, m) {
		int ui, vi, bi, ci;
		cin >> ui >> vi >> bi >> ci;
		--ui; --vi;
		g[ui].emplace_back(vi, make_pair(bi, ci));
	}
	vector<map<int, int>> dp(n);
	dp[0][0] = 0;
	rep(i, n) {
		for (const auto& [vci, vbi] : dp[i]) {
			for (const auto& [ti, tpi] : g[i]) {
				const auto& [tbi, tci] = tpi;
				int nbi = vbi + tbi, nci = vci + tci;
				auto itr = dp[ti].lower_bound(nci);
				if (itr != dp[ti].end() && itr->first == nci) itr->second = max(itr->second, nbi);
				else dp[ti][nci] = nbi;
			}
		}
	}
	double res = 0.0;
	for (const auto& [vci, vbi] : dp[n-1]) res = max(res, vbi/(double)vci);
	printf("%.14f\n", res);
	return 0;
}
