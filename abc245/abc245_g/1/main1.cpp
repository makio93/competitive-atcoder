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
    vector<vector<pair<ll, int>>> dist(n);
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
    rep(i, l) pq.emplace(0, a[b[i]], b[i]);
    while (!pq.empty()) {
        auto ppi = pq.top(); pq.pop();
        ll di = get<0>(ppi); int ai = get<1>(ppi), vi = get<2>(ppi);
        if (dist[vi].empty() || ((int)(dist[vi].size())==1&&dist[vi].back().second!=ai)) dist[vi].emplace_back(di, ai);
        else continue;
        for (const auto tpi : g[vi]) {
            int ti = tpi.first; ll ndi = di + tpi.second;
            pq.emplace(ndi, ai, ti);
        }
    }
    rep(i, n) {
        ll res = LINF;
        if (dist[i].empty() || ((int)(dist[i].size())==1&&dist[i][0].second==a[i])) res = -1;
        else if (dist[i][0].second != a[i]) res = dist[i][0].first;
        else res = dist[i][1].first;
        cout << res << (i<n-1?' ':'\n');
    }
    return 0;
}
