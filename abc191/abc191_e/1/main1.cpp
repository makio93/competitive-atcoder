// 学習1回目,解説AC

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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n), rg(n);
    rep(i, m) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        --ai; --bi;
        g[ai].emplace_back(bi, ci);
        rg[bi].emplace_back(ai, ci);
    }
    rep(i, n) {
        vector<int> dist(n, INF), rdist(n, INF);
        auto dijkstra = [](vector<int>& dist, vector<vector<pair<int, int>>>& g, int si) -> void {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[si] = 0;
            pq.emplace(0, si);
            while (!pq.empty()) {
                auto pi = pq.top(); pq.pop();
                int di = pi.first, vi = pi.second;
                if (dist[vi] != di) continue;
                for (auto tpi : g[vi]) {
                    int ti = tpi.first, ndi = di + tpi.second;
                    if (dist[ti] <= ndi) continue;
                    dist[ti] = ndi;
                    pq.emplace(ndi, ti);
                }
            }
        };
        dijkstra(dist, g, i);
        dijkstra(rdist, rg, i);
        int res = INF;
        rep(j, n) if (i != j) res = min(res, min(INF, dist[j]+rdist[j]));
        for (auto tpi : g[i]) if (tpi.first == i) res = min(res, tpi.second);
        if (res == INF) cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}
