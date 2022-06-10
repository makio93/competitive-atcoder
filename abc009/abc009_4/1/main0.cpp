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

Matrix multiply(Matrix A, Matrix B) {
    Matrix C(A.sz);
    rep(i, A.sz) rep(j, B.sz) {
        rep(k, C.sz) C.x[i][j] = (C.x[i][j] ^ (A.x[i][k] & B.x[k][j]));
    }
    return C;
}

Matrix matpow(Matrix A, ll t) {
    vector<Matrix> E(64, Matrix(A.sz));
    E[0] = A;
    rep(i, 63) E[i+1] = multiply(E[i], E[i]);
    Matrix res(A.sz);
    rep(i, res.sz) res.x[i][i] = ~(0);
    repr(i, 63) if (t & (1LL<<i)) res = multiply(res, E[i]);
    return res;
}

int main() {
    int k, m;
    cin >> k >> m;
    vector<unsigned> a(k), c(k);
    rep(i, k) cin >> a[i];
    rep(i, k) cin >> c[i];
    if (m <= k) {
        cout << a[m-1] << endl;
        return 0;
    }
    Matrix mat(k);
    rep(i, k) mat.x[0][i] = c[i];
    rep(i, k-1) mat.x[i+1][i] = ~(0);
    auto rmat = matpow(mat, m-k);
    unsigned res = 0;
    rep(i, k) res ^= rmat.x[0][i] & a[k-1-i];
    cout << res << endl;
    return 0;
}
