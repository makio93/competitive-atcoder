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

const int INF = (int)(1e9);

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
	ll res = 0;
	function<int(int, int)> dfs = [&](int vi, int pi) {
		vector<int> slst;
		int ssum = 0;
		for (const int& ti : g[vi]) if (ti != pi) {
			slst.push_back(dfs(ti, vi));
			ssum += slst.back();
		}
		if (n-1-ssum > 0) slst.push_back(n-1-ssum);
		int slen = slst.size();
		vector<vector<ll>> dp(slen+1, vector<ll>(3));
		rep(i, slen) rep(j, 3) {
			if (j-1 >= 0) dp[i+1][j] = dp[i][j-1] * slst[i] + dp[i][j];
			else dp[i+1][j] = slst[i] + dp[i][j];
		}
		res += dp[slen][2];
		return ssum + 1;
	};
	dfs(0, -1);
	cout << res << endl;
	return 0;
}
