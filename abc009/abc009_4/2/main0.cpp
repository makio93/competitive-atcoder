// 学習2回目,自力AC

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

template<typename T>
struct Matrix {
    int h, w;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, T val=0) : h(h), w(w), d(h, vector<T>(w, val)) {}
    Matrix& unit() {
        assert(h == w);
        rep(i, h) d[i][i] = ~0U;
        return *this;
    }
    const vector<T>& operator[](int i) const { return d[i]; }
    vector<T>& operator[](int i) { return d[i]; }
    Matrix operator*(const Matrix& a) const {
        assert(w == a.h);
        Matrix r(h, a.w);
        rep(i, h) rep(k, w) rep(j, a.w) {
            r[i][j] ^= d[i][k] & a[k][j];
        }
        return r;
    }
    Matrix pow(long long t) const {
        assert(h == w);
        if (!t) return Matrix(h, h).unit();
        if (t == 1) return *this;
        Matrix r = pow(t>>1);
        r = r * r;
        if (t&1) r = r * (*this);
        return r;
    }
};

int main() {
    int k, m;
    cin >> k >> m;
    --m;
    vector<unsigned> a(k), c(k);
    rep(i, k) cin >> a[i];
    rep(i, k) cin >> c[i];
    if (m < k) {
        cout << a[m] << endl;
        return 0;
    }
    Matrix<unsigned> mt(k, k);
    rep(i, k) mt[0][i] = c[i];
    rep(i, k-1) mt[i+1][i] = ~0U;
    mt = mt.pow(m-(k-1));
    unsigned res = 0U;
    rep(i, k) res ^= a[k-i-1] & mt[0][i];
    cout << res << endl;
    return 0;
}
