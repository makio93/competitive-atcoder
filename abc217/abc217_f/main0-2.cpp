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

// 本番WA,2

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
	int n, m;
	cin >> n >> m;
	combination cb(2*n+5);
	vector<int> a(m), b(m);
	map<int, set<int>> ab;
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		ab[ai].insert(bi-ai);
	}
	vector<vector<mint>> dp(2*n+1, vector<mint>(2*n+1));
	rep(i, 2*n) dp[i][i] = 1;
	rep(i, 2*n-1) if (ab.find(i)!=ab.end() && ab[i].find(1)!=ab[i].end()) dp[i][i+2] = 1;
	for (int k=4; k<=2*n; k+=2) {
		for (int l=0; l+k<=2*n; ++l) {
			int r = l + k, c = (r-l) / 4 * 2;
			dp[l][r] += dp[l][l+c] * dp[l+c][r] * cb((r-l)/2, c/2);
			if (ab.find(l)!=ab.end() && ab[l].find(k-1)!=ab[l].end()) dp[l][r] += dp[l+1][r-1];
		}
	}
	cout << dp[0][2*n].val() << endl;
	return 0;
}
