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
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<int> a(n), b(l);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, l) {
        cin >> b[i];
        b[i]--;
    }
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        int ui, vi, ci;
        cin >> ui >> vi >> ci;
        --ui; --vi;
        g[ui].emplace_back(vi, ci);
        g[vi].emplace_back(ui, ci);
    }
    vector<map<int, ll>> dist(n);
    priority_queue<pair<pair<ll, int>, int>, vector<pair<pair<ll, int>, int>>, greater<pair<pair<ll, int>, int>>> pq;
    rep(i, l) {
        pq.emplace(make_pair(0, a[b[i]]), b[i]);
        dist[b[i]][a[b[i]]] = 0;
    }
    while (!pq.empty()) {
        auto ppi = pq.top(); pq.pop();
        ll di = ppi.first.first;
        int ai = ppi.first.second, vi = ppi.second;
        if (dist[vi].find(ai)==dist[vi].end() || dist[vi][ai]!=di) continue;
        for (const auto& tpi : g[vi]) {
            ll ndi = di + tpi.second;
            int ti = tpi.first;
            if (dist[ti].find(ai) != dist[ti].end()) {
                if (dist[ti][ai] <= ndi) continue;
                else {
                    dist[ti][ai] = ndi;
                    pq.emplace(make_pair(ndi, ai), ti);
                }
            }
            else {
                if ((int)(dist[ti].size()) < 2) {
                    dist[ti][ai] = ndi;
                    pq.emplace(make_pair(ndi, ai), ti);
                }
                else {
                    pair<ll, int> mval = { ndi, ai };
                    for (const auto& pi : dist[ti]) mval = max(mval, { pi.second, pi.first });
                    if (mval == make_pair(ndi, ai)) continue;
                    dist[ti].erase(mval.second);
                    dist[ti][ai] = ndi;
                    pq.emplace(make_pair(ndi, ai), ti);
                }
            }
        }
    }
    rep(i, n) {
        ll res = LINF;
        if (dist[i].empty() || ((int)(dist[i].size())==1&&dist[i].begin()->first==a[i])) res = -1;
        else if ((int)(dist[i].size()) == 1) res = dist[i].begin()->second;
        else { for (const auto& pi : dist[i]) if (pi.first != a[i]) res = min(res, pi.second); }
        cout << res << (i<n-1?' ':'\n');
    }
    return 0;
}
