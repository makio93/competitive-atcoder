// 学習1回目,自力AC-2

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
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n));
    rep3(i, 1, n+1) {
        for (int i2=1,ten=1; i2<=i; i2*=10,++ten) if (i>=i2 && i<i2*10) dp[i][ten+1] += 26;
        rep3(j, 1, n) {
            for (int i2=1,ten=1; i2<i; i2*=10,++ten) {
                if (j-ten-1 <= 0) break;
                dp[i][j] += (dp[i-i2][j-ten-1] - dp[max(0, i-i2*10)][j-ten-1] + p) * 25;
                dp[i][j] %= p;
            }
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= p;
        }
    }
    ll res = 0;
    rep3(i, 1, n) {
        res += dp[n][i] - dp[n-1][i] + p;
        res %= p;
    }
    cout << res << endl;
    return 0;
}
