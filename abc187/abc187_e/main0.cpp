// 本番AC

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

v(v(int)) g;
v(int) parents;
void search(int v, int p=-1) {
    parents[v] = p;
    for (int to : g[v]) {
        if (to == p) continue;
        search(to, v);
    }
}

v(ll) c, cadd;
void addval(ll addv, int v, int p=-1) {
    c[v] += addv;
    for (int to : g[v]) {
        if (to == p) continue;
        addval(addv+cadd[to], to, v);
    }
}

int main(){
    int n, q;
    cin >> n;
    v(int) a(n-1), b(n-1);
    g = v(v(int))(n);
    rep(i, n-1) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    parents = v(int)(n);
    search(0);
    cadd = v(ll)(n);
    ll exc = 0;
    cin >> q;
    rep(i, q) {
        int t, e, x;
        cin >> t >> e >> x;
        --e;
        int fr, to;
        if (t == 1) {
            fr = a[e]; to = b[e];
        }
        else {
            fr = b[e]; to = a[e];
        }
        if (parents[fr] == to) {
            cadd[fr] += x;
        }
        else {
            cadd[to] -= x;
            exc += x;
        }
    }
    c = v(ll)(n, exc);
    addval(cadd[0], 0);
    rep(i, n) cout << c[i] << endl;
    return 0;
}
