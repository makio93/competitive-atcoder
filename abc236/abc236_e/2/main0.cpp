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

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    double li1 = 1.0, ri1 = (double)mval;
    while ((ri1-li1)/li1 > 1e-3) {
        double ci = sqrt(li1 * ri1);
        vector<vector<double>> dp(n+1, vector<double>(2, -1e18));
        dp[0][0] = dp[0][1] = 0.0;
        rep(i, n) {
            dp[i+1][0] = dp[i][1];
            dp[i+1][1] = max(dp[i][0], dp[i][1]) + (a[i] - ci);
        }
        if (max(dp[n][0], dp[n][1]) >= 0.0) li1 = ci;
        else ri1 = ci;
    }
    int li2 = 1, ri2 = mval + 1;
    while (ri2-li2 > 1) {
        int ci = li2 + (ri2-li2) / 2;
        vector<vector<int>> dp(n+1, vector<int>(2, -INF));
        dp[0][0] = dp[0][1] = 0;
        rep(i, n) {
            dp[i+1][0] = dp[i][1];
            dp[i+1][1] = max(dp[i][0], dp[i][1]) + (a[i]>=ci ? 1 : -1);
        }
        if (max(dp[n][0], dp[n][1]) > 0) li2 = ci;
        else ri2 = ci;
    }
    printf("%.9f\n%d\n", li1, li2);
    return 0;
}
