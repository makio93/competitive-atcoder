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

const ll mod = 998244353LL;
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
	combination cb(n*2);
	vector<int> ccnt(26);
	rep(i, n) ccnt[s[i]-'a']++;
	vector<vector<mint>> dp(27, vector<mint>(n+1));
	dp[0][0] = 1;
	rep(i, 26) rep(j, n+1) rep(k, min(j,ccnt[i])+1) dp[i+1][j] += dp[i][j-k] * cb(j, k);
	mint res = 0;
	rep3(i, 1, n+1) res += dp[26][i];
	cout << res.val() << endl;
	return 0;
}
