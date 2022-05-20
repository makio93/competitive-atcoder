// 復習2,自力AC

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

int main() {
    int n, m;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i], p[i]--;
    cin >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i], a[i]--, b[i]--;
    vector<vector<pair<int, int>>> g(n);
    dsu d(n);
    rep(i, m) if (!d.same(a[i], b[i])) {
        g[a[i]].emplace_back(b[i], i), g[b[i]].emplace_back(a[i], i);
        d.merge(a[i], b[i]);
    }
    vector<int> din(n);
    rep(i, n) din[i] = g[i].size();
    vector<int> ans;
    queue<int> que;
    bool ok = true;
    rep(i, n) if (din[i] == 1) {
        que.push(i);
        din[i]--;
    }
    while (!que.empty()) {
        int v = que.front(); que.pop();
        stack<int> path;
        vector<bool> visited(n);
        function<bool(int,int)> dfs = [&](int vi, int pi) -> bool {
            visited[vi] = true;
            if (p[vi] == v) {
                while (!path.empty()) {
                    ans.push_back(path.top()+1);
                    swap(p[a[path.top()]], p[b[path.top()]]);
                    path.pop();
                }
                return true;
            }
            for (auto tpi : g[vi]) if (tpi.first!=pi && !visited[tpi.first]) {
                path.push(tpi.second);
                if (dfs(tpi.first, vi)) return true;
                path.pop();
            }
            return false;
        };
        if (!dfs(v, -1)) {
            ok = false;
            break;
        }
        for (auto tpi : g[v]) if (din[tpi.first] > 0) {
            din[tpi.first]--;
            if (din[tpi.first] == 1) {
                que.push(tpi.first);
                din[tpi.first]--;
            }
        }
    }
    if (ok) {
        rep(i, n) if (p[i] != i) {
            ok = false;
            break;
        }
    }
    if (ok) {
        int k = ans.size();
        cout << k << endl;
        if (k > 0) rep(i, k) printf("%d%c", ans[i], (i<k-1?' ':'\n'));
        else cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}
