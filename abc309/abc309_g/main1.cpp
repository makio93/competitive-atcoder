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
struct combination {
	vector<mint> fact, ifact;
	combination(int n) : fact(n+1), ifact(n+1) {
		fact[0] = 1;
		for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
		ifact[n] = fact[n].inv();
		for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k<0 || k>n) return 0;
		return (fact[n] * ifact[k] * ifact[n-k]);
	}
};

int main() {
	int n, x;
	cin >> n >> x;
	combination cb(n);
	vector dp(n+1, vector(n+1, vector(1<<(x*2-1), mint(0))));
	dp[0][0][0] = 1;
	rep(i, n) rep(j, n+1) rep(k, 1<<(x*2-1)) {
		int nk = k / 2;
		dp[i+1][j][nk] += dp[i][j][k];
		if (j+1 <= n) rep(i2, x*2-1) {
			if (i+1+i2-(x-1) < 1 || i+1+i2-(x-1) > n) continue;
			if (!((nk>>i2)&1)) dp[i+1][j+1][nk^(1<<i2)] += dp[i][j][k];
		}
	}
	mint res = 0;
	rep(i, n+1) rep(j, 1<<(x*2-1)) res += dp[n][i][j] * cb.fact[n-i] * (i%2 == 0 ? 1 : -1);
	cout << res.val() << endl;
	return 0;
}
