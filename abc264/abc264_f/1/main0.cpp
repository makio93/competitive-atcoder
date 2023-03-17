// 学習1回目,自力AC

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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll LINF = (ll)(1e18);

int main() {
    int h, w;
    cin >> h >> w;
    vector<int> r(h), c(w);
    rep(i, h) cin >> r[i];
    rep(i, w) cin >> c[i];
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(4, LINF)));
    rep(i, 4) {
        ll val = 0;
        if (i & 1) val += c[0];
        if (i & (1<<1)) val += r[0];
        dp[0][0][i] = val;
    }
    rep(i, h) rep(j, w) {
        if (i==0 && j==0) continue;
        rep(i2, 4) {
            int vci = ((a[i][j] - '0') + __builtin_popcount(i2)) % 2;
            if (j-1 >= 0) {
                rep(j2, 2) {
                    int pid = (i2 & (1<<1)) | j2, pci = ((a[i][j-1] - '0') + __builtin_popcount(pid)) % 2;
                    if (pci != vci) continue;
                    chmin(dp[i][j][i2], dp[i][j-1][pid]+((i2&1)?c[j]:0));
                }
            }
            if (i-1 >= 0) {
                rep(j2, 2) {
                    int pid = (i2 & 1) | (j2 << 1), pci = ((a[i-1][j] - '0') + __builtin_popcount(pid)) % 2;
                    if (pci != vci) continue;
                    chmin(dp[i][j][i2], dp[i-1][j][pid]+((i2&(1<<1))?r[i]:0));
                }
            }
        }
    }
    ll res = LINF;
    rep(i, 4) res = min(res, dp[h-1][w-1][i]);
    cout << res << endl;
    return 0;
}
