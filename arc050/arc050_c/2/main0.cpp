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
    int h, w, m;
    vector<vector<T>> d;
    Matrix() {}
    Matrix(int h, int w, int m, T val=0) : h(h), w(w), m(m), d(h, vector<T>(w, val)) {}
    Matrix& unit() {
        assert(h == w);
        rep(i, h) d[i][i] = 1;
        return *this;
    }
    const vector<T>& operator[](int i) const { return d[i]; }
    vector<T>& operator[](int i) { return d[i]; }
    Matrix operator*(const Matrix& a) const {
        assert(w == a.h);
        Matrix r(h, a.w, m);
        rep(i, h) rep(k, w) rep(j, a.w) {
            r[i][j] = (r[i][j] + d[i][k] * a[k][j]) % m;
        }
        return r;
    }
    Matrix pow(long long t) const {
        assert(h == w);
        if (!t) return Matrix(h, h, m).unit();
        if (t == 1) return *this;
        Matrix r = pow(t>>1);
        r = r * r;
        if (t&1) r = r * (*this);
        return r;
    }
};

ll modpow(ll a, ll b, ll m) {
    ll p = 1, q = a;
    rep(i, 63) {
        if (b & (1LL<<i)) p = p * q % m;
        q = q * q % m;
    }
    return p;
}

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
    ll a, b;
    int m;
    cin >> a >> b >> m;
    ll g = gcd(a, b), c = b / g;
    ll gten = modpow(10, g, m);
    vector<vector<ll>> td1 = { { 10, 1 }, { 0, 1 } }, td2 = { { gten, 1 }, { 0, 1 } };
    Matrix<ll> mat1(2, 2, m), mat2(2, 2, m);
    mat1.d = td1, mat2.d = td2;
    mat1 = mat1.pow(a-1);
    mat2 = mat2.pow(c-1);
    ll res = ((mat1[0][0] + mat1[0][1]) % m) * ((mat2[0][0] + mat2[0][1]) % m) % m; 
    cout << res << endl;
    return 0;
}
