// 本番実装(未完成)

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
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int n, m;
    cin >> n >> m;
    v(v(int)) g(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        ai--; bi--;
        g[ai].pb(bi);
        g[bi].pb(ai);
    }
    /*
    v(v(int)) dist(n, v(int)(n, INF));
    rep(i, n) dist[i][i] = 0;
    rep(i, n) for (int j : g[i]) dist[i][j] = 1;
    rep(k, n) rep(i, n) rep(j, n) {
        dist[i][j] = min(dist[i][j], min((int)(INF), dist[i][k]+dist[k][j]));
    }
    */
   /*
    dsu d(n);
    rep(i, n) rep(j, n) {
        if (i==j) continue;
        if (dist[i][j] > 1) continue;
        d.merge(i, j);
    }
    */
    set<int> unused;
    rep(i, n) unused.insert(i);
    while (!unused.empty()) {
        v(int) tmp;
        auto itr = unused.begin();
        tmp.pb(*itr);
        for (auto to : g[*itr]) tmp.pb(to);
        rep2(i, 1, sz(tmp)-1) for (int j=i+1; j<sz(tmp); ++j) {
            if (tmp[j] == -1) continue;
            bool ok = false;
            rep(i2, sz(g[i])) if (g[i][i2] == tmp[j]) ok = true;
            if (!ok) tmp[j] = -1;
        }

    }
    return 0;
}
