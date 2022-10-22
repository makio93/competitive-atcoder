// 解説AC

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

#define bit(x, i) (((x)>>(i))&1)
template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const double INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n+m), y(n+m);
    rep(i, n+m) cin >> x[i] >> y[i];
    vector<vector<double>> dp(1<<(n+m), vector<double>(n+m, INF));
    rep(i, n+m) dp[1<<i][i] = hypot(x[i], y[i]);
    rep(i, (1<<(n+m))-1) {
        int mul = 1 << __builtin_popcount(i>>n);
        rep(j, n+m) if (bit(i, j)) {
            rep(j2, n+m) if (!bit(i, j2)) chmin(dp[i|(1<<j2)][j2], dp[i][j]+hypot(x[j2]-x[j],y[j2]-y[j])/mul);
        }
    }
    double res = INF;
    for (int i=(1<<n)-1; i<1<<(n+m); i+=1<<n) rep(j, n+m) if (bit(i, j)) {
        int mul = 1 << __builtin_popcount(i>>n);
        chmin(res, dp[i][j]+hypot(x[j],y[j])/mul);
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}
