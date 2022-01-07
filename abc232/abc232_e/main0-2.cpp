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

// 復習2回目,自力AC

using mint = modint998244353;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;
    vector<mint> dp(4);
    dp[3] = 1;
    const vector<vector<mint>> muly = { { h-2, h-1, 0, 0 }, { 1, 0, 0, 0 }, { 0, 0, h-2, h-1 }, { 0, 0, 1, 0 } }, 
        mulx = { { w-2, 0, w-1, 0 }, { 0, w-2, 0, w-1 }, { 1, 0, 0, 0 }, { 0, 1, 0, 0 } };
    rep(i, k) {
        vector<mint> ndp(4);
        rep(j, 4) rep(j2, 4) ndp[j2] += dp[j] * muly[j][j2] + dp[j] * mulx[j][j2];
        swap(ndp, dp);
    }
    int id = (x2==x1 ? 1 : 0) + (y2==y1 ? 2 : 0);
    cout << dp[id].val() << endl;
    return 0;
}
