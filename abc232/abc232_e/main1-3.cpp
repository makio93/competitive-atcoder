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

// 復習3回目,解説AC

using mint = modint998244353;

int main() {
    int h, w, k, y1, x1, y2, x2;
    cin >> h >> w >> k >> y1 >> x1 >> y2 >> x2;
    --y1; --x1; --y2; --x2;
    const vector<int> my = { 1, h-1 }, mx = { 1, w-1 };
    array<array<mint, 2>, 2> dp;
    dp[y1!=y2?1:0][x1!=x2?1:0] = 1;
    rep(i1, k) {
        array<array<mint, 2>, 2> ndp;
        rep(i, 2) rep(j, 2) rep(j2, 2) {
            ndp[j2][j] += dp[i][j] * (my[j2] - (j2==i?1:0));
            ndp[i][j2] += dp[i][j] * (mx[j2] - (j2==j?1:0));
        }
        dp = move(ndp);
    }
    cout << dp[0][0].val() << endl;
    return 0;
}
