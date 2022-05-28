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
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		cout << mint(m).pow(n).val() << endl;
		return 0;
	}
	vector<vector<mint>> dp(n, vector<mint>(m+2));
	rep3(i, 1, m+1) dp[0][i] = 1;
	rep(i, n-1) {
		rep3(j, 1, m+1) {
			int ai = min(m+1, j+k), bi = max(1, j-k+1);
			dp[i+1][ai] += dp[i][j];
			dp[i+1][m+1] -= dp[i][j];
			dp[i+1][1] += dp[i][j];
			dp[i+1][bi] -= dp[i][j];
		}
		rep3(j, 1, m+1) dp[i+1][j+1] += dp[i+1][j];
	}
	mint res = 0;
	rep3(j, 1, m+1) res += dp[n-1][j];
	cout << res.val() << endl;
	return 0;
}
