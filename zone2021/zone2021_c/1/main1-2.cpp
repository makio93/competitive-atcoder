// 学習1回目,解説AC2

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
    vector<vector<int>> a(n, vector<int>(5));
    rep(i, n) rep(j, 5) cin >> a[i][j];
    vector<vector<int>> dp(4, vector<int>(1<<5));
    dp[0][0] = INF;
    rep(i, n) {
        auto ndp = dp;
        rep(j, 5) rep(i2, 3) rep(j2, 1<<5) 
            if ((j2>>j)&1) ndp[i2][j2] = max(ndp[i2][j2], min(ndp[i2][j2^(1<<j)], a[i][j]));
        rep(j1, 3) rep(j2, 1<<5) dp[j1+1][j2] = max(dp[j1+1][j2], ndp[j1][j2]);
    }
    cout << dp[3][(1<<5)-1] << endl;
    return 0;
}
