// 復習2,解説AC

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

struct edge {
    int to, id;
    edge(int to, int id) : to(to), id(id) {}
};

int main() {
    int n, m;
    cin >> n;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    cin >> m;
    dsu d(n);
    vector<vector<edge>> g(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        if (d.same(ai, bi)) continue;
        d.merge(ai, bi);
        g[ai].emplace_back(bi, i);
        g[bi].emplace_back(ai, i);
    }
    vector<int> ans;
    rep(i, n) if (i == d.leader(i)) {
        auto get = [&](auto& get, int vi, int tar, int pi=-1) -> bool {
            if (p[vi] == tar) return true;
            for (auto ti : g[vi]) if (ti.to != pi) {
                if (get(get, ti.to, tar, vi)) {
                    ans.push_back(ti.id+1);
                    swap(p[vi], p[ti.to]);
                    return true;
                }
            }
            return false;
        };
        auto dfs = [&](auto& dfs, int vi, int pi=-1) -> bool {
            for (auto ti : g[vi]) if (ti.to != pi) {
                if (!dfs(dfs, ti.to, vi)) return false;
            }
            if (!get(get, vi, vi)) return false;
            return true;
        };
        if (!dfs(dfs, i)) {
            cout << -1 << endl;
            return 0;
        }
    }
    int k = ans.size();
    cout << k << endl;
    if (k == 0) cout << endl;
    else rep(i, k) printf("%d%c", ans[i], (i<k-1?' ':'\n'));
    return 0;
}
