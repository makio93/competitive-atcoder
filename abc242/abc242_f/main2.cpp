// 公式解説,解法1,AC

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

const ll mod = 998244353LL;
using mint = modint998244353;
struct combination {
	vector<mint> fact, ifact;
	combination(int n) : fact(n+1), ifact(n+1) {
		assert(n < mod);
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
	int n, m, b, w;
	cin >> n >> m >> b >> w;
	combination cb(n*m+5);
	auto init = [&](vector<vector<mint>>& dp, int x) -> void {
		dp.resize(n+1, vector<mint>(m+1));
		rep(i, n+1) rep(j, m+1) {
			dp[i][j] = cb(i*j, x);
			rep(i2, i+1) rep(j2, j+1) if (i2<i || j2<j) {
				dp[i][j] -= dp[i2][j2] * cb(i, i2) * cb(j, j2);
			}
		}
	};
	vector<vector<mint>> dp1, dp2;
	init(dp1, b), init(dp2, w);
	mint res = 0;
	rep(i1, n+1) rep(i2, n-i1+1) rep(j1, m+1) rep(j2, m-j1+1) {
		res += cb(n, i1) * cb(n-i1, i2) * cb(m, j1) * cb(m-j1, j2) * dp1[i1][j1] * dp2[i2][j2];
	}
	cout << res.val() << endl;
	return 0;
}
