// 復習1,自力AC

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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    double l = 0.0, r = (double)mval + 1.0;
    while (r-l >= 1e-5) {
        double c = l + (r-l) / 2.0;
        vector<double> b(n);
        rep(i, n) b[i] = a[i] - c;
        vector<vector<double>> dp(n+1, vector<double>(2));
        rep(i, n) {
            dp[i+1][0] = max(dp[i][0], dp[i][1]) + b[i];
            dp[i+1][1] = dp[i][0];
        }
        double val = max(dp[n][0], dp[n][1]);
        if (val >= 0.0) l = c;
        else r = c;
    }
    cout << l << endl;
    int li = 0, ri = mval + 1;
    while (ri-li > 1) {
        int ci = li + (ri-li) / 2;
        vector<int> b(n);
        rep(i, n) b[i] = (a[i] >= ci) ? 1 : -1;
        vector<vector<int>> dp(n+1, vector<int>(2));
        rep(i, n) {
            dp[i+1][0] = max(dp[i][0], dp[i][1]) + b[i];
            dp[i+1][1] = dp[i][0];
        }
        int val = max(dp[n][0], dp[n][1]);
        if (val > 0) li = ci;
        else ri = ci;
    }
    cout << li << endl;
    return 0;
}
