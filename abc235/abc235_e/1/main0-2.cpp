// 復習1,自力AC2,クエリ先読みなし解法

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

const int INF = (int)(1e9);

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m), b(m), c(m);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    vector<pair<int, int>> elst;
    rep(i, m) elst.emplace_back(c[i], i);
    sort(all(elst));
    vector<vector<pair<int, int>>> g(n);
    dsu d(n);
    rep(i, m) if (!d.same(a[elst[i].second], b[elst[i].second])) {
        d.merge(a[elst[i].second], b[elst[i].second]);
        g[a[elst[i].second]].emplace_back(b[elst[i].second], elst[i].first);
        g[b[elst[i].second]].emplace_back(a[elst[i].second], elst[i].first);
    }
    int nlog = 1, ntmp = 1;
    while (ntmp*2 < n) {
        ntmp *= 2;
        ++nlog;
    }
    vector<vector<int>> par(nlog, vector<int>(n, -1));
    vector<int> dep(n, INF);
    vector<vector<int>> cost(nlog, vector<int>(n));
    auto dfs = [&](auto dfs, int vi=0, int di=0) -> void {
        dep[vi] = di;
        for (auto pi : g[vi]) if (dep[pi.first] == INF) {
            par[0][pi.first] = vi;
            cost[0][pi.first] = pi.second;
            dfs(dfs, pi.first, di+1);
        }
    };
    dfs(dfs);
    rep(i, nlog-1) rep(j, n) {
        if (par[i][j] == -1) continue;
        par[i+1][j] = par[i][par[i][j]];
        cost[i+1][j] = max({ cost[i+1][j], cost[i][j], cost[i][par[i][j]] });
    }
    rep(i1, q) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        --ui; --vi;
        if (dep[ui] < dep[vi]) swap(ui, vi);
        int dist = 0;
        repr(i, nlog) if (((dep[ui]-dep[vi])>>i)&1) {
            dist = max(dist, cost[i][ui]);
            ui = par[i][ui];
        }
        if (ui != vi) {
            repr(i, nlog) if (par[i][ui] != par[i][vi]) {
                dist = max({ dist, cost[i][ui], cost[i][vi] });
                ui = par[i][ui];
                vi = par[i][vi];
            }
            dist = max({ dist, cost[0][ui], cost[0][vi] });
        }
        if (dist < wi) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
