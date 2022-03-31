// 復習2,自力,AC

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

const ll mod = 998244353LL;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    const vector<int> depx = { h-1, 1 }, depy = { w-1, 1 };
    int sx = (x1 == x2) ? 1 : 0, sy = (y1 == y2) ? 1 : 0;
    vector<vector<ll>> dp(2, vector<ll>(2));
    rep(i, 2) rep(j, 2) if (i==sx && j==sy) dp[i][j] = 1;
    rep(i0, k) {
        vector<vector<ll>> ndp(2, vector<ll>(2));
        rep(i1, 2) rep(j1, 2) {
            int i2 = (i1 + 1) % 2, j2 = (j1 + 1) % 2;
            ndp[i2][j1] = (ndp[i2][j1] + dp[i1][j1] * depx[i2]) % mod;
            ndp[i1][j2] = (ndp[i1][j2] + dp[i1][j1] * depy[j2]) % mod;
            ndp[i1][j1] = (ndp[i1][j1] + dp[i1][j1] * (depx[i1]-1)) % mod;
            ndp[i1][j1] = (ndp[i1][j1] + dp[i1][j1] * (depy[j1]-1)) % mod;
        }
        swap(ndp, dp);
    }
    cout << dp[1][1] << endl;
    return 0;
}
