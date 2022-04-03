// 復習2,解説2

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
    int h, w, k, x1, y1, x2, y2;
    cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    array<array<mint, 2>, 2> dp;
    array<int, 2> mrow = { 1, h-1 }, mcol = { 1, w-1 };
    dp[x1!=x2][y1!=y2] = 1;
    rep(i, k) {
        array<array<mint, 2>, 2> ndp;
        rep(i, 2) rep(j, 2) rep(a, 2) {
            ndp[a][j] += dp[i][j] * (mrow[a] - (i==a));
            ndp[i][a] += dp[i][j] * (mcol[a] - (j==a));
        }
        dp = move(ndp);
    }
    cout << dp[0][0].val() << endl;
    return 0;
}
