// 本番WA

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
	ll n;
	vector<mint> fact, ifact, com;
	combination(ll n, int k) : n(n), fact(k+1), ifact(k+1), com(k+1) {
		fact[0] = 1;
		for (int i=1; i<=k; ++i) fact[i] = fact[i-1] * i;
		ifact[k] = fact[k].inv();
		for (int i=k; i>=1; --i) ifact[i-1] = ifact[i] * i;
		com[0] = 1;
		for (int i=1; i<=k; ++i) com[i] = com[i-1] * (n-i+1) / i;
	}
	mint operator()(ll n, int k) {
		if (k<0 || k>n) return 0;
		return (fact[n] * ifact[k] * ifact[n-k]);
	}
	mint operator()(int k) {
		if (k<0 || k>n) return 0;
		if (n-k < k) k = n-k;
		return com[k];
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll rsum = 0;
	rep3(i, 1, n) rsum += a[i];
	if (a[0]-k-rsum < 0LL) {
		cout << 0 << endl;
		return 0;
	}
	a[0] -= k;
	a[0] -= rsum;
	a.push_back(k-1);
	ll nval = 0, kval = 0;
	rep(i, n+1) nval += a[i];
	rep(i, n+1) kval = max(kval, min((ll)a[i], nval-a[i]));
	combination cb(nval, (int)kval);
	sort(all(a));
	mint res = 1;
	rep(i, n) res *= cb(a[i]);
	cout << res.val() << endl;
	return 0;
}
