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
	auto f = [&](int x) {
		vector<vector<mint>> db(n+1, vector<mint>(m+1));
		rep(i, n+1) rep(j, m+1) {
			rep(i2, i+1) rep(j2, j+1) {
				mint val = cb(i2*j2, x);
				val *= cb(i, i2) * cb(j, j2);
				if ((i-i2+j-j2)%2 == 1) val *= -1;
				db[i][j] += val;
			}
		}
		return db;
	};
	auto bl = f(b), wh = f(w);
	mint res = 0;
	rep(i1, n+1) rep(j1, m+1) rep(i2, n+1) rep(j2, m+1) {
		if (i1+i2 > n) break;
		if (j1+j2 > m) break;
		mint val = cb(n, i1) * cb(n-i1, i2);
		val *= cb(m, j1) * cb(m-j1, j2);
		val *= bl[i1][j1] * wh[i2][j2];
		res += val;
	}
	cout << res.val() << endl;
	return 0;
}
