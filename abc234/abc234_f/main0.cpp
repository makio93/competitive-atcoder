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

// 本番AC

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
	string s;
	cin >> s;
	int n = s.length();
	sort(all(s));
	vector<pair<char, int>> runs;
	runs.emplace_back(s[0], 1);
	rep3(i, 1, n) {
		if (s[i] == runs.back().first) runs.back().second++;
		else runs.emplace_back(s[i], 1);
	}
	combination cb(n+1);
	int m = runs.size();
	vector<vector<mint>> dp(m+1, vector<mint>(n+1));
	dp[0][0] = 1;
	rep(i, m) rep(j, n+1) {
		rep(j2, runs[i].second+1) {
			if (j+j2 > n) break;
			dp[i+1][j+j2] += dp[i][j] * cb(j+j2, j2);
		}
	}
	mint res = 0;
	rep3(i, 1, n+1) res += dp[m][i];
	cout << res.val() << endl;
	return 0;
}
