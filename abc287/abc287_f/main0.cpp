// 本番TLE

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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<vector<mint>> dp0(n, vector<mint>(n+1)), dp1(n, vector<mint>(n+1));
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		bool leaf = true;
		for (const int& ti : g[vi]) if (ti != pi) {
			dfs(dfs, ti, vi);
			leaf = false;
		}
		if (leaf) dp0[vi][0] = dp1[vi][0] = 1;
		else {
			vector<mint> tdp;
			dp0[vi][0] = dp1[vi][0] = 1;
			for (const int& ti : g[vi]) if (ti != pi) {
				tdp = dp0[ti];
				rep3(i, 1, n+1) tdp[i] += dp1[ti][i-1];
				auto ndp = convolution(dp0[vi], tdp);
				rep(i, n+1) dp0[vi][i] = ndp[i];
			}
			for (const int& ti : g[vi]) if (ti != pi) {
				tdp = dp0[ti];
				rep(i, n+1) tdp[i] += dp1[ti][i];
				auto ndp = convolution(dp1[vi], tdp);
				rep(i, n+1) dp1[vi][i] = ndp[i];
			}
		}
	};
	dfs(dfs);
	vector<mint> res(n+1);
	rep(i, n+1) res[i] = dp0[0][i];
	rep3(i, 1, n+1) res[i] += dp1[0][i-1];
	rep3(i, 1, n+1) cout << res[i].val() << endl;
	return 0;
}
