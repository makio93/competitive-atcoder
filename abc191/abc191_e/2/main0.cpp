// 学習2回目,自力AC

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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        --ai; --bi;
        g[ai].emplace_back(bi, ci);
    }
    vector<ll> dist;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    rep(i, n) {
        dist.assign(n, LINF);
        for (const auto& tpi : g[i]) pq.emplace((ll)tpi.second, tpi.first);
        while (!pq.empty()) {
            auto [di, vi] = pq.top(); pq.pop();
            if (dist[vi] <= di) continue;
            dist[vi] = di;
            for (const auto& tpi : g[vi]) {
                int ti = tpi.first;
                ll ndi = di + tpi.second;
                if (dist[ti] <= ndi) continue;
                pq.emplace(ndi, ti);
            }
        }
        if (dist[i] == LINF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}
