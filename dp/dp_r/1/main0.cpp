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

const ll mod = (ll)(1e9) + 7;

vector<vector<ll>> mat_mul(vector<vector<ll>> m1, vector<vector<ll>> m2) {
    int r1 = m1.size(), r2 = m2.size(), c2 = m2.front().size();
    vector<vector<ll>> res(r1, vector<ll>(c2));
    rep(i, r1) rep(j, c2) rep(i2, r2) res[i][j] = (res[i][j] + m1[i][i2] * m2[i2][j]) % mod;
    return res;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> mat, ll ki) {
    int mlen = mat.size();
    vector<vector<ll>> res(mlen, vector<ll>(mlen));
    rep(i, mlen) res[i][i] = 1;
    while (ki > 0) {
        if (ki&1) res = mat_mul(mat, res);
        mat = mat_mul(mat, mat);
        ki >>= 1;
    }
    return res;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<ll>> ta(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n) ta[j][i] = a[i][j];
    vector<vector<ll>> nvec(n, vector<ll>(1, 1));
    nvec = mat_mul(mat_pow(ta, k), nvec);
    ll res = 0;
    rep(i, n) res = (res + nvec[i][0]) % mod;
    cout << res << endl;
    return 0;
}
