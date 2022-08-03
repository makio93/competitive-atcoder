// 自力AC

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

const ll mod = (ll)(1e9) + 7;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<vector<ll>> memo(h, vector<ll>(w, -1));
    auto dfs = [&](auto dfs, int yi, int xi) -> ll {
        if (memo[yi][xi] != -1) return memo[yi][xi];
        ll rval = 1;
        const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        rep(i1, 4) {
            int ny = yi + dy[i1], nx = xi + dx[i1];
            if (ny<0 || ny>=h || nx<0 || nx>=w || a[ny][nx]<=a[yi][xi]) continue;
            rval = (rval + dfs(dfs, ny, nx)) % mod;
        }
        return memo[yi][xi] = rval;
    };
    ll res = 0;
    rep(i, h) rep(j, w) res = (res + dfs(dfs, i, j)) % mod;
    cout << res << endl;
    return 0;
}
