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

// 本番WA2

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
	ll nval = 0;
	rep(i, n+1) nval += a[i];
	combination cb((int)nval);
	sort(all(a));
	mint res = 1;
	ll tval = nval;
	rep(i, n) {
		res *= cb((int)tval, a[i]);
		tval -= a[i];
	}
	cout << (res).val() << endl;
	return 0;
}
