// 学習2回目,解説AC

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
    vector<vector<pair<int, int>>> g(n), rg(n);
    rep(i, m) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        --ai; --bi;
        g[ai].emplace_back(bi, ci);
        rg[bi].emplace_back(ai, ci);
    }
    vector<ll> dist, rdist;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    auto calc = [&n,&pq](vector<vector<pair<int, int>>>& tg, vector<ll>& tdist, int si) -> void {
        tdist.assign(n, LINF);
        pq.emplace(0, si);
        while (!pq.empty()) {
            auto [di, vi] = pq.top(); pq.pop();
            if (tdist[vi] <= di) continue;
            tdist[vi] = di;
            for (const auto& tpi : tg[vi]) {
                int ti = tpi.first;
                ll ndi = di + tpi.second;
                if (tdist[ti] <= ndi) continue;
                pq.emplace(ndi, ti);
            }
        }
    };
    rep(i, n) {
        calc(g, dist, i);
        calc(rg, rdist, i);
        ll res = LINF;
        for (const auto& tpi : g[i]) if (tpi.first == i) res = min(res, (ll)tpi.second);
        rep(j, n) if (j!=i && dist[j]!=LINF && rdist[j]!=LINF) res = min(res, dist[j]+rdist[j]); 
        if (res == LINF) res = -1;
        cout << res << endl;
    }
    return 0;
}
