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

// 

using mint = modint998244353;

int main() {
	int n, m;
	cin >> n >> m;
	function<int(int,int,int)> mdig = [&m](int v1, int v2, int v3) -> int { return v1 * (m+1) * (m+1) + v2 * (m+1) + v3; };
	vector<vector<mint>> dp(n+1, vector<mint>(mdig(m, m, m)+1));
	dp[0][mdig(m, m, m)] = 1;
	rep(i, n) rep(j1, m+1) rep(j2, m+1) rep(j3, m+1) rep(i2, m) {
		if (i2 <= j1) dp[i+1][mdig(i2, j2, j3)] += dp[i][mdig(j1, j2, j3)];
		else if (i2 <= j2) dp[i+1][mdig(j1, i2, j3)] += dp[i][mdig(j1, j2, j3)];
		else if (i2 <= j3) dp[i+1][mdig(j1, j2, i2)] += dp[i][mdig(j1, j2, j3)];
	}
	mint res = 0;
	rep(i1, m) rep(i2, m) rep(i3, m) res += dp[n][mdig(i1, i2, i3)];
	cout << res.val() << endl;
	return 0;
}
