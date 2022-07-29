// 復習2回目,自力,TLE

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
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<vector<int>> g(n);
    rep(i, m) {
        int ui, vi;
        cin >> ui >> vi;
        --ui; --vi;
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    vector<ll> dist(n, LINF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto pi = pq.top(); pq.pop();
        ll di = pi.first; int vi = pi.second;
        if (dist[vi] != di) continue;
        for (auto ti : g[vi]) {
            ll ndi = di + (h[ti] < h[vi] ? (h[ti]-h[vi]) : (ll)(h[ti]-h[vi])*2);
            if (dist[ti] <= ndi) continue;
            dist[ti] = ndi;
            pq.emplace(ndi, ti);
        }
    }
    ll res = 0;
    rep(i, n) res = max(res, -dist[i]);
    cout << res << endl;
    return 0;
}
