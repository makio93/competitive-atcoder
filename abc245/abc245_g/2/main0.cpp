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
    vector<vector<pair<ll, int>>> dist(n, vector<pair<ll, int>>(2, { LINF, -1 }));
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    function<bool(int,ll,int)> update = [&](int vi, ll di, int ki) {
        rep(i2, 2) if (dist[vi][i2].second == ki) {
            if (dist[vi][i2].first <= di) return false;
            dist[vi][i2].first = di;
            if (dist[vi][0].first > dist[vi][1].first) swap(dist[vi][0], dist[vi][1]);
            return true;
        }
        repr(i2, 2) if (dist[vi][i2].first > di) {
            dist[vi][i2].first = di;
            dist[vi][i2].second = ki;
            if (dist[vi][0].first > dist[vi][1].first) swap(dist[vi][0], dist[vi][1]);
            return true;
        }
        return false;
    };
    rep(i, l) {
        update(b[i], 0LL, a[b[i]]);
        pq.emplace(0LL, make_pair(b[i], a[b[i]]));
    }
    while (!pq.empty()) {
        auto [di, pi] = pq.top(); pq.pop();
        auto [vi, ki] = pi;
        bool ok = false;
        rep(i2, 2) if (dist[vi][i2] == make_pair(di, ki)) ok = true;
        if (!ok) continue;
        for (const auto& tpi : g[vi]) {
            ll ndi = di + tpi.second;
            if (!update(tpi.first, ndi, ki)) continue;
            pq.emplace(ndi, make_pair(tpi.first, ki));
        }
    }
    rep(i, n) {
        ll res = LINF;
        rep(i2, 2) if (dist[i][i2].second != -1 && dist[i][i2].second != a[i]) res = min(res, dist[i][i2].first);
        if (res == LINF) res = -1;
        cout << res << (i<n-1?' ':'\n');
    }
    return 0;
}
