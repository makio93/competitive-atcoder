// 本番WA

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

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    --x; --y;
    vector<vector<pair<int, int>>> g(n);
    vector<ll> t(m), k(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b >> t[i] >> k[i];
        --a; --b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    vector<ll> dist(n, (ll)(LINF));
    que.emplace(0LL, x);
    dist[x] = 0LL;
    while (!que.empty()) {
        auto pi = que.top(); que.pop();
        ll nt = pi.first;
        int vv = pi.second;
        if (dist[vv] != nt) continue;
        rep(i, (int)(g[vv].size())) {
            int tov = g[vv][i].first, nmi = g[vv][i].second;
            ll tt = (nt+k[nmi]-1)/k[nmi]*k[nmi] + t[nmi];
            if (dist[tov] <= tt) continue;
            que.emplace(tt, tov);
            dist[tov] = tt;
        }
    }
    if (dist[y] == (ll)(LINF)) cout << -1 << endl;
    else cout << dist[y] << endl;
    return 0;
}
