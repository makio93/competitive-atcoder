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

const int INF = (int)(1e9);
template<typename T>
struct Matrix {
	int n;
	ll m;
	vector<vector<T>> d;
	Matrix() {}
	Matrix(int n, ll m, T val=0) : n(n), m(m), d(n, vector<T>(n, val)) {}
	Matrix& unit() {
		rep(i, n) d[i][i] = 1;
		return *this;
	}
	const vector<T>& operator[](int i) const { return d[i]; }
	vector<T>& operator[](int i) { return d[i]; }
	Matrix operator*(const Matrix& a) const {
		Matrix r(n, m);
		rep(i, n) rep(k, n) rep(j, n) {
			r[i][j] += d[i][k] * a[k][j] % m;
			r[i][j] %= m;
		}
		return r;
	}
	Matrix pow(long long t) const {
		if (!t) return Matrix(n, n).unit();
		if (t == 1) return *this;
		Matrix r = pow(t>>1);
		r = r * r;
		if (t&1) r = r * (*this);
		return r;
	}
};

int main() {
	ll a, x, m;
	cin >> a >> x >> m;
	Matrix<ll> mt(2, m);
	mt[0][0] = a % m;
	mt[0][1] = mt[1][1] = 1 % m;
	mt = mt.pow(x);
	ll res = mt[0][1];
	cout << res << endl;
	return 0;
}
