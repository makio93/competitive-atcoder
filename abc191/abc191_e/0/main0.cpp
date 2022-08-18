// 自力AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e15)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int n, m;
    cin >> n >> m;
    v(v(p2(int,ll))) g(n);
    rep(i, m) {
        int ai, bi;
        ll ci;
        cin >> ai >> bi >> ci;
        --ai; --bi;
        g[ai].eb(bi, ci);
    }
    rep(i, n) {
        vector<ll> dist(n, (ll)(LINF));
        priority_queue<p2(ll,int), v(p2(ll,int)), greater<p2(ll,int)>> que;
        rep(j, sz(g[i])) {
            que.emplace(g[i][j].second, g[i][j].first);
            dist[g[i][j].first] = min(dist[g[i][j].first], g[i][j].second);
        }
        while (!que.empty()) {
            auto pi = que.top(); que.pop();
            int vi = pi.second;
            ll d = pi.first;
            if (dist[vi] != d) continue;
            rep(j2, sz(g[vi])) {
                auto to = g[vi][j2];
                int ni = to.first;
                ll nd = d + to.second;
                if (dist[ni] <= nd) continue;
                que.emplace(nd, ni);
                dist[ni] = nd;
            }
        }
        if (dist[i] == (ll)(LINF)) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}
