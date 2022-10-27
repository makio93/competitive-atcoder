// 学習3回目,自力AC

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

struct edge { int u, v, w, id; };

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<edge> e(m+q);
    rep(i, m+q) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].u--; e[i].v--;
        e[i].id = i;
    }
    sort(all(e), [](auto li, auto ri) -> bool { return li.w < ri.w; });
    dsu d(n);
    vector<bool> res(q);
    rep(i, m+q) {
        if (!d.same(e[i].u, e[i].v)) {
            if (e[i].id < m) d.merge(e[i].u, e[i].v);
            if (e[i].id >= m) res[e[i].id-m] = true;
        }
    }
    rep(i, q) {
        if (res[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
