// 学習3回目,自力AC1

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
    ll p;
    cin >> n >> p;
    vector<vector<ll>> dp(n, vector<ll>(2)), ndp;
    dp[0][0] = dp[1][1] = 1;
    rep3(i, 1, n) {
        ndp.assign(n, vector<ll>(2));
        rep(j, n) {
            ndp[j][0] = (ndp[j][0] + dp[j][0] + dp[j][1]) % p;
            if (j-1 >= 0) {
                ndp[j][0] = (ndp[j][0] + dp[j-1][0] * 3) % p;
                ndp[j][1] = (ndp[j][1] + dp[j-1][1]) % p;
            }
            if (j-2 >= 0) ndp[j][1] = (ndp[j][1] + dp[j-2][0] * 2) % p;
        }
        dp = move(ndp);
    }
    rep3(i, 1, n) cout << dp[i][0] << (i<n-1?' ':'\n');
    return 0;
}
