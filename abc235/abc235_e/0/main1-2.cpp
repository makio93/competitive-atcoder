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

// 解説AC2(クエリ先読み無し)

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
    vector<pair<int, int>> elst;
    rep(i, m) elst.emplace_back(c[i], i);
    sort(elst.begin(), elst.end());
    dsu dc(n);
    rep(i, m) if (!dc.same(a[elst[i].second], b[elst[i].second])) {
        g[a[elst[i].second]].emplace_back(b[elst[i].second], elst[i].second);
        g[b[elst[i].second]].emplace_back(a[elst[i].second], elst[i].second);
        dc.merge(a[elst[i].second], b[elst[i].second]);
    }
    vector<pair<int, int>> par(n, { -1, -1 });
    vector<int> depth(n, -1);
    static function<void(int,int,int,int)> dfs = [&](int vi, int pi, int ei, int di) -> void {
        par[vi] = { pi, ei };
        depth[vi] = di;
        for (auto tpi : g[vi]) if (tpi.first != pi) dfs(tpi.first, vi, tpi.second, di+1);
    };
    dfs(0, -1, -1, 0);
    int klog = 0;
    rep(i, 31) if ((n>>i)&1) klog = max(klog, i);
    vector<vector<int>> pars(klog+1, vector<int>(n, -1)), mcost(klog+1, vector<int>(n, INF));
    rep(i, n) {
        pars[0][i] = par[i].first;
        if (par[i].second != -1) mcost[0][i] = c[par[i].second];
    }
    rep(i, klog) rep(j, n) {
        if (pars[i][j] != -1) {
            pars[i+1][j] = pars[i][pars[i][j]];
            mcost[i+1][j] = max(mcost[i][j], mcost[i][pars[i][j]]);
        }
    }
    rep(i, q) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        --ui; --vi;
        static function<int(int,int)> acost = [&](int ai, int bi) -> int {
            if (depth[ai] > depth[bi]) swap(ai, bi);
            int cval = 0;
            repr(i2, klog+1) if (((depth[bi]-depth[ai])>>i2)&1) {
                cval = max(cval, mcost[i2][bi]);
                bi = pars[i2][bi];
            }
            if (ai == bi) return cval;
            repr(i2, klog+1) if (pars[i2][ai] != pars[i2][bi]) {
                cval = max({ cval, mcost[i2][ai], mcost[i2][bi] });
                ai = pars[i2][ai];
                bi = pars[i2][bi];
            }
            return max({ cval, mcost[0][ai], mcost[0][bi] });
        };
        if (wi < acost(ui, vi)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
