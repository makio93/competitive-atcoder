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

// 解説AC

const ll mod = 998244353LL;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int ui, vi;
        cin >> ui >> vi;
        --ui; --vi;
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    ll res = 1;
    vector<bool> visited(n);
    int mval = 0, nval = 0;
    function<void(int)> dfs = [&](int v) -> void {
        visited[v] = true;
        ++nval; mval += g[v].size();
        for (int ti : g[v]) if (!visited[ti]) dfs(ti);
    };
    rep(i, n) if (!visited[i]) {
        mval = 0; nval = 0;
        dfs(i);
        if (mval != nval*2) {
            res = 0;
            break;
        }
        res = res * 2 % mod;
    }
    cout << res << endl;
    return 0;
}
