// 復習1回目,解説AC

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

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    Matrix ta(n);
    rep(i, n) rep(j, n) ta.x[j][i] = a[i][j];
    auto mat = matpow(ta, k, mod);
    ll res = 0;
    rep(i, n) rep(j, n) res = (res + mat.x[i][j]) % mod;
    cout << res << endl;
    return 0;
}
