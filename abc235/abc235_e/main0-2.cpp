// 復習2回目,自力AC2

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

const int INF = (int)(1.5e9);

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m), b(m), c(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    vector<vector<pair<int, int>>> g(n);
    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int li, int ri) -> bool { return c[li] < c[ri]; });
    dsu ds(n);
    rep(i, m) if (!ds.same(a[ord[i]], b[ord[i]])) {
        g[a[ord[i]]].emplace_back(b[ord[i]], c[ord[i]]);
        g[b[ord[i]]].emplace_back(a[ord[i]], c[ord[i]]);
        ds.merge(a[ord[i]], b[ord[i]]);
    }
    int lcnt = 0, tmp = 1;
    while (tmp*2 <= n) {
        ++lcnt;
        tmp *= 2;
    }
    vector<vector<pair<int, int>>> dp(lcnt+1, vector<pair<int, int>>(n, { -1, 0 }));
    vector<int> dep(n);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1, int di=0) -> void {
        dep[vi] = di;
        for (auto [ti, tci] : g[vi]) if (ti != pi) {
            dp[0][ti] = { vi, tci };
            dfs(dfs, ti, vi, di+1);
        }
    };
    dfs(dfs);
    rep(i, lcnt) rep(j, n) {
        if (dp[i][j].first == -1) dp[i+1][j] = dp[i][j];
        else dp[i+1][j] = { dp[i][dp[i][j].first].first, max(dp[i][j].second, dp[i][dp[i][j].first].second) };
    }
    rep(i, q) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        --ui; --vi;
        if (dep[ui] > dep[vi]) swap(ui, vi);
        int cval = 0;
        rep(j, lcnt+1) if (((dep[vi]-dep[ui])>>j)&1) {
            cval = max(cval, dp[j][vi].second);
            vi = dp[j][vi].first;
        }
        repr(j, lcnt+1) if (dp[j][ui].first != dp[j][vi].first) {
            cval = max({ cval, dp[j][ui].second, dp[j][vi].second });
            ui = dp[j][ui].first;
            vi = dp[j][vi].first;
        }
        if (ui != vi) {
            cval = max({ cval, dp[0][ui].second, dp[0][vi].second });
            ui = dp[0][ui].first;
            vi = dp[0][vi].first;
        }
        if (wi < cval) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
