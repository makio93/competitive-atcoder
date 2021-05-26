#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC（ACL用いず）

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n, -1) {}
    int find(int x) {
        if (d[x] < 0) return x;
        return (d[x] = find(d[x]));
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return (find(x) == find(y)); }
    int size(int x) { return -d[find(x)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m), l(m), r(m);
    rep(i, m) cin >> c[i] >> l[i] >> r[i];
    vector<tuple<int, int, int>> clr(m);
    rep(i, m) clr[i] = { c[i], l[i]-1, r[i] };
    sort(all(clr));
    UnionFind uf(n+1);
    ll res = 0; int cnt = 0;
    rep(i, m) {
        int ci = get<0>(clr[i]), ui = get<1>(clr[i]), vi = get<2>(clr[i]);
        if (!uf.same(ui, vi)) {
            uf.unite(ui, vi);
            res += ci;
            ++cnt;
        }
    }
    if (cnt < n) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
