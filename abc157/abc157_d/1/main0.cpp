// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

// UnionFind
struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n,-1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> ab(n), cd(n);
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        uf.unite(a, b);
        ab[a].pb(b);
        ab[b].pb(a);
    }
    rep(i, k) {
        int c, d;
        cin >> c >> d;
        --c; --d;
        cd[c].pb(d);
        cd[d].pb(c);
    }
    vi ans(n);
    rep(i, n) {
        int cnt = uf.size(i) - sz(ab[i]) - 1;
        rep(j, sz(cd[i])) {
            if (uf.same(i, cd[i][j])) --cnt;
        }
        ans[i] = cnt;
    }
    rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    return 0;
}
