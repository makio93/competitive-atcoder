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

// ライブラリ整備用に少しmain2を手直し

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
    ll N;
    int B, K;
    cin >> N >> B >> K;
    vector<int> C(K);
    rep(i, K) cin >> C[i];
    Matrix A(B);
    rep(i, B) rep(j, K) A.x[i][(i*10+C[j])%B]++;
    Matrix res = matpow(A, N, mod);
    cout << res.x[0][0] << endl;
    return 0;
}
