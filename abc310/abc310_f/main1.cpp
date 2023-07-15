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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<mint>> dp(n+1, vector<mint>(1<<11));
	dp[0][1] = 1;
	rep(i, n) rep(j, 1<<11) {
		rep3(j2, 1, min(10, a[i])+1) {
			int ti = (j | (j << j2)) & ((1<<11) - 1);
			dp[i+1][ti] += dp[i][j] * mint(a[i]).inv();
		}
		if (a[i] > 10) dp[i+1][j] += dp[i][j] * mint(a[i]-10) / (a[i]);
	}
	mint res = 0;
	rep(i, 1<<10) res += dp[n][i|(1<<10)];
	cout << res.val() << endl;
	return 0;
}
