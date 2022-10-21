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

const ll mod = (ll)(1e9) + 7;

void matmul(vector<vector<ll>>& lm, vector<vector<ll>>& rm) {
    int n = lm.size();
    vector<vector<ll>> tmp(n, vector<ll>(n));
    rep(i, n) rep(j, n) rep(i2, n) tmp[i][j] = (tmp[i][j] + lm[i][i2] * rm[i2][j]) % mod;
    swap(tmp, rm);
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    vector<vector<ll>> b(n, vector<ll>(n));
    rep(i, n) rep(j, n) b[i][j] = a[j][i];
    vector<vector<ll>> p = b, c(n, vector<ll>(n));
    rep(i, n) c[i][i] = 1;
    while (k) {
        if (k&1LL) matmul(p, c);
        matmul(p, p);
        k >>= 1;
    }
    ll res = 0;
    rep(i, n) rep(j, n) res = (res + c[i][j]) % mod;
    cout << res << endl;
    return 0;
}
