// 学習3回目,自力AC2

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
    int n, p;
    cin >> n >> p;
    vector dp(2, vector(n, vector(2, 0LL)));
    dp[0][0][0] = dp[0][1][1] = 1;
    rep3(i, 1, n) rep(j, n) {
        dp[i%2][j][0] = dp[i%2][j][1] = 0;
        dp[i%2][j][0] = (dp[i%2][j][0] + dp[(i-1)%2][j][0] + dp[(i-1)%2][j][1]) % p;
        if (j-1 >= 0) {
            dp[i%2][j][0] = (dp[i%2][j][0] + dp[(i-1)%2][j-1][0] * 3) % p;
            dp[i%2][j][1] = (dp[i%2][j][1] + dp[(i-1)%2][j-1][1]) % p;
        }
        if (j-2 >= 0) dp[i%2][j][1] = (dp[i%2][j][1] + dp[(i-1)%2][j-2][0] * 2) % p;
    }
    rep3(i, 1, n) cout << dp[(n-1)%2][i][0] << (i<n-1?' ':'\n');
    return 0;
}
