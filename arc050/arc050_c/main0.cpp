// 学習0回目,ヒント有り,自力AC

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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
	ll a, b, m;
	cin >> a >> b >> m;
	if (a < b) swap(a, b);
	ll g = gcd(a, b);
	auto mat_mul = [&](vector<vector<ll>> x, vector<vector<ll>> y) -> vector<vector<ll>> {
		vector<vector<ll>> ret(2, vector<ll>(2));
		rep(i1, 2) rep(j1, 2) rep(i2, 2) ret[i1][j1] = (ret[i1][j1] + x[i1][i2] * y[i2][j1]) % m;
		return ret;
	};
	auto mat_pow = [&](vector<vector<ll>> x, ll p) -> vector<vector<ll>> {
		vector<vector<ll>> ret(2, vector<ll>(2));
		rep(i1, 2) ret[i1][i1] = 1;
		while (p > 0) {
			if (p&1) ret = mat_mul(x, ret);
			x = mat_mul(x, x);
			p >>= 1;
		}
		return ret;
	};
	auto mod_pow = [&](auto mod_pow, ll x, ll p) -> ll {
		if (p == 0) return 1;
		if (p%2 == 1) return x * mod_pow(mod_pow, x, p-1) % m;
		else {
			ll t = mod_pow(mod_pow, x, p/2);
			return t * t % m;
		}
	};
	ll r = b / g, gten = mod_pow(mod_pow, 10, g);
	vector<vector<ll>> mul1 = { { 10%m, 1 }, { 0, 1 } }, mul2 = { { gten%m, 1 }, { 0, 1 } };
	vector<vector<ll>> amul = mat_pow(mul1, a-1), rmul = mat_pow(mul2, r-1);
	ll aval = 0, rval = 0;
	rep(i, 2) aval = (aval + amul[0][i]) % m;
	rep(i, 2) rval = (rval + rmul[0][i]) % m;
	ll res = aval * rval % m;
	cout << res << endl;
	return 0;
}
