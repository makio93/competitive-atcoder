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

using mint = modint998244353;

int main() {
	ll n, m;
	cin >> n >> m;
	int blen = 0;
	rep(i, 60) if ((m>>i)&1) blen = max(blen, i+1);
	if (n > blen) {
		cout << 0 << endl;
		return 0;
	}
	vector<vector<mint>> dp(n, vector<mint>(blen));
	mint mxval = m - (1LL<<(blen-1)) + 1;
	rep(i, blen-1) dp[0][i] = mint(1LL<<i);
	dp[0][blen-1] = mxval;
	rep(i, n-1) rep(j, blen-1) rep3(j2, j+1, blen) {
		if (j2 < blen-1) dp[i+1][j2] += dp[i][j] * mint(1LL<<j2);
		else dp[i+1][j2] += dp[i][j] * mxval;
	}
	mint res = 0;
	rep(i, blen) res += dp[n-1][i];
	cout << res.val() << endl;
	return 0;
}
