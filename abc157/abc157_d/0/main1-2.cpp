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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct UnionFind {
    vi v;
    UnionFind(int n=0) : v(n, -1) {}
    int find(int x) {
        if (v[x] < 0) return x;
        return (v[x] = find(v[x]));
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (x > y) swap(x, y);
        v[x] += v[y];
        v[y] = x;
        return true;
    }
    int size(int x) {
        return abs(v[find(x)]);
    }
    bool same(int x, int y) {
        if (find(x) == find(y)) return true;
        else return false;
    }
};

int d[100005];
vi blk[100005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a]++; d[b]++;
        uf.unite(a, b);
    }
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        blk[a].push_back(b);
        blk[b].push_back(a);
    }
    rep(i, n) {
        int ans;
        ans = uf.size(i) - 1 - d[i];
        for (int o : blk[i]) {
            if (uf.same(i, o)) ans--;
        }
        printf("%d%c", ans, i==n-1?'\n':' ');
    }
    return 0;
}

