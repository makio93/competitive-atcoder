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

// 復習3回目,自力AC

using mint = modint998244353;

int main() {
    int h, w, k, y1, x1, y2, x2;
    cin >> h >> w >> k >> y1 >> x1 >> y2 >> x2;
    --y1; --x1; --y2; --x2;
    const vector<vector<int>> my = { { 1, 1 }, { h-1, h-1 } }, mx = { { 1, w-1 }, { 1, w-1 } };
    vector<vector<mint>> dp(2, vector<mint>(2));
    dp[(y1!=y2?1:0)][(x1!=x2?1:0)] = 1;
    rep(i1, k) {
        vector<vector<mint>> ndp(2, vector<mint>(2));
        rep(i, 2) rep(j, 2) rep(j2, 2) {
            int sub = 1 - j2;
            ndp[i^j2][j] += dp[i][j] * (my[i^j2][j] - sub);
            ndp[i][j^j2] += dp[i][j] * (mx[i][j^j2] - sub);
        }
        swap(ndp, dp);
    }
    cout << dp[0][0].val() << endl;
    return 0;
}
