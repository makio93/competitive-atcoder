// 自力で実装、小課題2まで解こうとしてみた、WA

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

using mint = modint1000000007;
using matrix = vector<vector<mint>>;

matrix mpow(matrix& a, ll p) {
	int b = a.size();
	if (p == 0LL) {
		matrix emat(b, vector<mint>(b));
		rep(i, b) emat[i][i] = 1;
		return emat;
	}
	else if (p%2LL==1LL) return mpow(a, p-1);
	else {
		matrix res = mpow(a, p/2), res2(b, vector<mint>(b));
		rep(i, b) rep(j, b) rep(i2, b) res2[i][j] += res[i][i2] * res[i2][j];
		return res2;
	}
}

int main() {
	ll n;
	int b, k;
	cin >> n >> b >> k;
	vector<int> c(k);
	rep(i, k) cin >> c[i];
	matrix a(b, vector<mint>(b, 0));
	rep(i, b) rep(j, k) {
		int nval = (i * 10 + c[j]) % b;
		a[i][nval]++;
	}
	matrix res = mpow(a, n);
	cout << res[0][0].val() << endl;
	return 0;
}
