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

// 解説AC

const ll mod = 998244353LL;
using mint = modint998244353;

struct combination {
	vector<mint> fact, ifact;
	combination(int n):fact(n+1),ifact(n+1) {
		assert(n < mod);
		fact[0] = 1;
		for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
		ifact[n] = fact[n].inv();
		for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
	}
	mint operator()(int n, int k) {
		if (k < 0 || k > n) return 0;
		return fact[n]*ifact[k]*ifact[n-k];
	}
};

int main() {
	int r, g, b, k, x, y, z;
	cin >> r >> g >> b >> k;
	cin >> x >> y >> z;
	combination cb(max({r,g,b,k}));
	int rl = k - y, rr = r; int gl = k - z, gr = g; int bl = k - x, br = b;
	vector<mint> a1(r+g+1), a2(r+g+1);
	rep3(i, rl, rr+1) a1[i] = cb(r, i);
	rep3(i, gl, gr+1) a2[i] = cb(g, i);
	auto arr1 = convolution(a1, a2);
	mint res = 0;
	rep3(i, bl, br+1) if (k-i>=0 && k-i<=r+g) res += cb(b, i) * arr1[k-i];
	cout << res.val() << endl;
	return 0;
}
