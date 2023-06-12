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
    vector<vector<double>> memo(1<<(n+m+1), vector<double>(n+m+1));
    vector<vector<bool>> exist(1<<(n+m+1), vector<bool>(n+m+1));
    function<double(int,int)> f = [&](int si, int vi) {
        if (exist[si][vi]) return memo[si][vi];
        exist[si][vi] = true;
        if (!(si&(1<<vi))) return memo[si][vi] = DINF;
        if (__builtin_popcount(si) == 1) return memo[si][vi] = dist(n+m, vi, 0);
        int pi = si ^ (1<<vi);
        double rval = DINF;
        rep(i, n+m+1) if (pi&(1<<i)) rval = min(rval, f(pi, i) + dist(i, vi, pi));
        return memo[si][vi] = rval;
    };
    double res = DINF;
    rep(i, 1<<m) res = min(res, f((1<<n)-1+(1<<(n+m))+(i<<n), n+m));
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
