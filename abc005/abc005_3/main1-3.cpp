// 解説AC3

#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

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

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e8)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const string YES = "yes";
const string NO = "no";

struct edge {
    int to, cap, rev;
};

vector<vector<edge>> g;
vi dist, iter;
int dfs(int v, int t, int f) {
    if (v==t) return f;
    for (int &i=iter[v]; i<sz(g[v]); ++i) {
        edge &e = g[v][i];
        if (e.cap>0 && dist[e.to]>dist[v]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int main(){
    int t, n;
    cin >> t >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int m;
    cin >> m;
    vi b(m);
    rep(i, m) cin >> b[i];
    g = vector<vector<edge>>(m+n+2);
    iter = vi(m+n+2);
    auto add_edge = [&] (int from, int to) {
        g[from].pb({to, 1, sz(g[to])});
        g[to].pb({from, 0, sz(g[from])-1});
    };
    rep(i, n) {
        add_edge(0, i+1);
        rep(j, m) {
            if (a[i]>=b[j]-t && a[i]<=b[j]) {
                add_edge(i+1, j+n+1);
            }
        }
    }
    rep(i, m) add_edge(i+n+1, m+n+1);
    queue<int> q;
    auto ps = [&] (int v, int d) {
        q.push(v);
        dist[v] = d;
    };
    auto bfs = [&] (int s) {
        dist.assign(m+n+2, -1);
        ps(s, 0);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            rep(i, sz(g[v])) {
                edge &e = g[v][i];
                if (e.cap>0 && dist[e.to]<0) {
                    ps(e.to, dist[v]+1);
                }
            }
        }
    };
    auto max_flow = [&] (int s, int t) {
        int flow = 0;
        while (1) {
            bfs(s);
            if (dist[t] < 0) return flow;
            iter.assign(m+n+2, 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    };
    if (max_flow(0, m+n+1) >= m) cout << YES << endl;
    else cout << NO << endl;
    return 0;
}
