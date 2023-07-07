// 解説AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

vector<vi> g;
vector<vi> parent;
vi depth;
void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    rep(i, sz(g[v])) {
        if (g[v][i] != p) dfs(g[v][i], v, d+1);
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int k=0; k*k<sz(g); ++k) {
        if (((depth[b]-depth[a])>>k) & 1) b = parent[k][b];
    }
    if (a == b) return a;
    repr(k, sz(parent)) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }
    return parent[0][a];
}

int main(){
    int n, q;
    cin >> n >> q;
    g = vector<vi>(n);
    map<pii, int> egs;
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        egs[{a, b}] = egs[{b, a}] = i;
        g[a].pb(b);
        g[b].pb(a);
    }
    vi u(q), v(q), c(q);
    rep(i, q) {
        cin >> u[i] >> v[i] >> c[i];
        u[i]--; v[i]--;
    }
    parent = vector<vi>(1, vi(n));
    depth = vi(n, -1);
    dfs(0, -1, 0);
    for (int k=0; (k+1)*(k+1)<n; ++k) {
        parent.pb(vi(n));
        rep(i, n) {
            if (parent[k][i] < 0) parent[k+1][i] = -1;
            else parent[k+1][i] = parent[k][parent[k][i]];
        }
    }
    dsu d(n);
    vi tol(n), ans(n-1, 0);
    rep(i, n) tol[i] = i;
    repr(i, q) {
        int to = lca(u[i], v[i]);
        to = tol[d.leader(to)];
        int u1 = tol[d.leader(u[i])];
        while (u1 != to) {
            int tov = parent[0][u1], toeg = egs[{u1, tov}];
            ans[toeg] = c[i];
            tov = d.leader(tov);
            int nl = d.merge(u1, tov);
            u1 = tol[nl] = tol[u1] = tol[tov];
        }
        to = tol[d.leader(to)];
        int v1 = tol[d.leader(v[i])];
        while (v1 != to) {
            int tov = parent[0][v1], toeg = egs[{v1, tov}];
            ans[toeg] = c[i];
            tov = d.leader(tov);
            int nl = d.merge(v1, tov);
            v1 = tol[nl] = tol[v1] = tol[tov];
        }
    }
    rep(i, n-1) cout << ans[i] << endl;
    return 0;
}
