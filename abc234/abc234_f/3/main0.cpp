// 学習3回目,バチャ本番,自力AC

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
	string s;
	cin >> s;
	int n = s.length();
	combination cb(n+1);
	vector<int> ccnt(26);
	rep(i, n) ccnt[s[i]-'a']++;
	vector<mint> dp(n+1), ndp;
	dp[0] = 1;
	rep(i, 26) {
		ndp.assign(n+1, 0);
		rep(j, n+1) rep(k, ccnt[i]+1) {
			if (j+k > n) break;
			ndp[j+k] += dp[j] * cb(j+k, k);
		}
		swap(dp, ndp);
	}
	mint res = 0;
	rep3(i, 1, n+1) res += dp[i];
	cout << res.val() << endl;
	return 0;
}
