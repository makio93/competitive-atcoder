// 学習0回目,ヒント有,自力AC

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

const ll mod = (ll)(1e9) + 7;

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<ll>> b(n, vector<ll>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	rep(i, n) rep(j, n) b[j][i] = a[i][j];
	auto mat_mul = [&](vector<vector<ll>> x, vector<vector<ll>> y) -> vector<vector<ll>> {
		vector<vector<ll>> ret(n, vector<ll>(n));
		rep(i1, n) rep(j1, n) rep(i2, n) ret[i1][j1] = (ret[i1][j1] + x[i1][i2] * y[i2][j1]) % mod;
		return ret;
	};
	auto mat_pow = [&](vector<vector<ll>> x, ll p) -> vector<vector<ll>> {
		vector<vector<ll>> ret(n, vector<ll>(n));
		rep(i1, n) ret[i1][i1] = 1;
		while (p > 0) {
			if (p%2 == 1) ret = mat_mul(x, ret);
			x = mat_mul(x, x);
			p >>= 1;
		}
		return ret;
	};
	auto mat = mat_pow(b, k);
	ll res = 0;
	rep(i, n) rep(j, n) res = (res + mat[i][j]) % mod;
	cout << res << endl;
	return 0;
}
