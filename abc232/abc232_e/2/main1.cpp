// 復習2,解説1

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

using mint = modint998244353;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    const vector<vector<int>> dx = { { h-2, 1 }, { h-1, 0 } }, dy = { { w-2, 1 }, { w-1, 0 } };
    vector<vector<mint>> dp(2, vector<mint>(2));
    dp[x1==x2][y1==y2] = 1;
    rep(ki, k) {
        vector<vector<mint>> pdp(2, vector<mint>(2));
        swap(pdp, dp);
        rep(i, 2) rep(j1, 2) rep(j2, 2) {
            dp[j2][i] += pdp[j1][i] * dx[j1][j2];
            dp[i][j2] += pdp[i][j1] * dy[j1][j2];
        }
    }
    cout << dp[1][1].val() << endl;
    return 0;
}
