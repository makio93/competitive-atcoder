// 学習1回目,解説AC

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

const double DINF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n+m), y(n+m);
    rep(i, n+m) cin >> x[i] >> y[i];
    function<double(int,int,int)> dist = [&](int fi, int ti, int si) {
        int fxi = (fi < n+m) ? x[fi] : 0, fyi = (fi < n+m) ? y[fi] : 0;
        int txi = (ti < n+m) ? x[ti] : 0, tyi = (ti < n+m) ? y[ti] : 0;
        int mul = 1 << __builtin_popcount((si >> n) & ((1<<m) - 1));
        return sqrt((fxi-txi)*(ll)(fxi-txi) + (fyi-tyi)*(ll)(fyi-tyi)) / mul;
    };
    vector<vector<double>> dp(1<<(n+m+1), vector<double>(n+m+1, DINF));
    rep(i, 1<<(n+m+1)) rep(j, n+m+1) if (i&(1<<j)) {
        if (__builtin_popcount(i) == 1) dp[i][j] = dist(n+m, j, 0);
        int pi = i ^ (1<<j);
        rep(j2, n+m+1) if (pi&(1<<j2)) dp[i][j] = min(dp[i][j], dp[pi][j2] + dist(j2, j, pi));
    }
    double res = DINF;
    rep(i, 1<<m) res = min(res, dp[(1<<n)-1+(1<<(n+m))+(i<<n)][n+m]);
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
