// 本番WA2

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
	int h, w, k;
	cin >> h >> w >> k;
	combination cb(h*w+2);
	vector<mint> dp(h+w+1);
	mint res = 0;
	rep3(i, 1, h+w+1) {
		rep3(j, 1, i) {
			int hi = j, wi = i - j;
			dp[i] += mint(hi*wi) * cb(hi*wi, k);
		}
		mint val = dp[i], mul = 1;
		rep3(j, 1, i) {
			mul *= 2;
			if (j%2 == 1) val -= dp[i-j] * mul;
			else val += dp[i-j] * mul;
		}
		res += val;
	}
	res /= cb(h*w, k);
	cout << res.val() << endl;
	return 0;
}
