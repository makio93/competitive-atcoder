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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	combination cb(h+w+2);
	vector<vector<mint>> dp(h, vector<mint>(w));
	rep(i, h) rep(j, w) {
		if (i-1 >= 0) {
			dp[i][j] += dp[i-1][j];
			if (s[i-1][j]=='Y' && s[i][j]=='Y') dp[i][j] += cb(i-1+j, j);
		}
		if (j-1 >= 0) {
			dp[i][j] += dp[i][j-1];
			if (s[i][j-1]=='Y' && s[i][j]=='Y') dp[i][j] += cb(i+j-1, j-1);
		}
	}
	mint res = 0;
	rep(i, h) rep(j, w) if (s[i][j] == 'Y') {
		mint dr = cb((h-1-i)+(w-1-j), w-1-j);
		if (i-1>=0 && s[i-1][j]=='Y') {
			mint ai = cb(i-1+j, j) * dr, bi = dp[i-1][j] * dr;
			res += ai + bi * 2;
		}
		if (j-1>=0 && s[i][j-1]=='Y') {
			mint ai = cb(i+j-1, j-1) * dr, bi = dp[i][j-1] * dr;
			res += ai + bi * 2;
		}
	}
	cout << res.val() << endl;
	return 0;
}
