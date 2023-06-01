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
    vector<int> rcnt(n);
    vector<pair<ll, int>> dist1(n, { LINF, -1 }), dist2(n, { LINF, -1 });
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    rep(i, l) pq.emplace(0LL, make_pair(b[i], a[b[i]]));
    while (!pq.empty()) {
        auto [di, pi] = pq.top(); pq.pop();
        auto [vi, ki] = pi;
        if (rcnt[vi] == 0) {
            rcnt[vi]++;
            dist1[vi] = { di, ki };
        }
        else if (rcnt[vi] == 1 && dist1[vi].second != ki) {
            rcnt[vi]++;
            dist2[vi] = { di, ki };
        }
        else continue;
        for (const auto& tpi : g[vi]) {
            int ti = tpi.first;
            ll ndi = di + tpi.second;
            if (dist1[ti].first <= ndi && dist2[ti].first <= ndi) continue;
            pq.emplace(ndi, make_pair(ti, ki));
        }
    }
    rep(i, n) {
        ll res = LINF;
        if (dist1[i].second != -1 && dist1[i].second != a[i]) res = dist1[i].first;
        else if (dist2[i].second != -1 && dist2[i].second != a[i]) res = dist2[i].first;
        else res = -1;
        cout << res << (i<n-1?' ':'\n');
    }
    return 0;
}
