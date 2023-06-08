// 学習1回目,自力AC

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

const ll LINF = (ll)(1e18);

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> y(n), z(n);
    rep(i, n) cin >> y[i];
    rep(i, n) cin >> z[i];
    vector<pair<int, int>> vlst;
    vlst.emplace_back(0, 0);
    vlst.emplace_back(x, n+1);
    rep(i, n) vlst.emplace_back(y[i], i+1);
    rep(i, n) vlst.emplace_back(z[i], -(i+1));
    sort(all(vlst));
    int m = vlst.size();
    vector<int> xlst(m), ilst(m);
    int si = -1;
    rep(i, m) {
        xlst[i] = vlst[i].first;
        ilst[i] = vlst[i].second;
        if (ilst[i] == 0) si = i;
    }
    vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(m, vector<ll>(2, LINF)));
    ll res = LINF;
    dp[si][si][0] = dp[si][si][1] = 0;
    rep(k, m) for (int l=0; l+k<m; ++l) {
        int r = l + k;
        if (dp[l][r][0] == LINF) continue;
        if (l-1>=0 && ((ilst[l-1]==n+1 || ilst[l-1]<=0) || (z[ilst[l-1]-1]>=xlst[l] && z[ilst[l-1]-1]<=xlst[r]))) {
            dp[l-1][r][0] = min(dp[l-1][r][0], dp[l][r][0]+xlst[l]-xlst[l-1]);
            dp[l-1][r][1] = min(dp[l-1][r][1], dp[l-1][r][0]+xlst[r]-xlst[l-1]);
            if (ilst[l-1] == n+1) res = min(res, dp[l-1][r][0]);
            if (ilst[r] == n+1) res = min(res, dp[l-1][r][1]);
        }
        if (r+1<m && ((ilst[r+1]==n+1 || ilst[r+1]<=0) || (z[ilst[r+1]-1]>=xlst[l] && z[ilst[r+1]-1]<=xlst[r]))) {
            dp[l][r+1][1] = min(dp[l][r+1][1], dp[l][r][1]+xlst[r+1]-xlst[r]);
            dp[l][r+1][0] = min(dp[l][r+1][0], dp[l][r+1][1]+xlst[r+1]-xlst[l]);
            if (ilst[r+1] == n+1) res = min(res, dp[l][r+1][1]);
            if (ilst[l] == n+1) res = min(res, dp[l][r+1][0]);
        }
    }
    if (res == LINF) res = -1;
    cout << res << endl;
    return 0;
}
