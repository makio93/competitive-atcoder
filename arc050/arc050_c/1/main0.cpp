// 復習1回目,自力AC

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

struct Matrix {
    int sz;
    vector<vector<ll>> x;
    Matrix(int sz=0) : sz(sz), x(sz, vector<ll>(sz)) {}
};

Matrix multiply(Matrix A, Matrix B, ll m=(ll)(1e9)+7) {
    Matrix C(A.sz);
    rep(i, A.sz) rep(j, B.sz) {
        rep(k, C.sz) C.x[i][j] = (C.x[i][j] + A.x[i][k] * B.x[k][j]) % m;
    }
    return C;
}

Matrix matpow(Matrix A, ll t, ll m=(ll)(1e9)+7) {
    vector<Matrix> E(64, Matrix(A.sz));
    E[0] = A;
    rep(i, 63) E[i+1] = multiply(E[i], E[i], m);
    Matrix res(A.sz);
    rep(i, res.sz) res.x[i][i] = 1;
    repr(i, 63) if (t & (1LL<<i)) res = multiply(res, E[i], m);
    return res;
}

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
    ll g = gcd(a, b);
    Matrix mat1(2), mat2(2);
    mat1.x = { { 10, 1 }, { 0, 1 } };
    auto amat = matpow(mat1, a-1, m);
    ll gv = modpow(10, g, m);
    mat2.x = { { gv, 1 }, { 0, 1 } };
    auto bmat = matpow(mat2, b/g-1, m);
    ll res = (amat.x[0][0] + amat.x[0][1]) * (bmat.x[0][0] + bmat.x[0][1]) % m;
    cout << res << endl;
    return 0;
}
