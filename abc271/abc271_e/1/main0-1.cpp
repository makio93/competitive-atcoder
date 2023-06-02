// 学習1回目,自力TLE1

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    vector<int> c(m);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi >> c[i];
        --ai; --bi;
        g[ai].emplace_back(bi, i);
    }
    vector<int> e(k);
    rep(i, k) {
        cin >> e[i];
        e[i]--;
    }
    vector<vector<int>> elst(m);
    rep(i, k) elst[e[i]].push_back(i);
    map<pair<int, int>, ll> dist;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    dist[{0, -1}] = 0;
    pq.emplace(0, -1, 0);
    while (!pq.empty()) {
        auto [di, ri, vi] = pq.top(); pq.pop();
        if (dist[{vi, ri}] != di) continue;
        for (const auto& tpi : g[vi]) {
            ll ndi = di + c[tpi.second];
            int ti = tpi.first, tei = tpi.second, trind = upper_bound(all(elst[tei]), ri) - elst[tei].begin();
            if (trind >= (int)(elst[tei].size())) continue;
            int tri = elst[tei][trind];
            if (dist.find({ti, tri}) != dist.end() && dist[{ti, tri}] <= ndi) continue;
            dist[{ti, tri}] = ndi;
            pq.emplace(ndi, tri, ti);
        }
    }
    ll res = -1;
    for (const auto& pi : dist) if (pi.first.first == n-1) {
        if (res == -1) res = pi.second;
        else res = min(res, pi.second);
    }
    cout << res << endl;
    return 0;
}
