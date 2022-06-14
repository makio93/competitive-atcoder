// 学習1回目,解説2の後,自力研究,AC

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
        rep(j, 3) rep(i2, 1<<5) {
            int aval = INF;
            rep(j2, 5) if ((i2>>j2)&1) aval = min(aval, a[i][j2]);
            rep(j2, 1<<5) if ((i2&j2) == i2) ndp[j+1][j2] = max(ndp[j+1][j2], min(dp[j][j2^i2], aval));
        }
        swap(ndp, dp);
    }
    cout << dp[3][(1<<5)-1] << endl;
    return 0;
}
