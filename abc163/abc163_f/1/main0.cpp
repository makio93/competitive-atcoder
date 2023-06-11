// 学習1回目,自力WA

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

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<int> sz(n), par(n, -1);
    vector<vector<int>> roots(n), parents(n), vg(n);
    function<void(int,int)> dfs = [&](int vi, int pi) {
        par[vi] = pi;
        if (parents[c[vi]].empty()) {
            roots[c[vi]].push_back(vi);
            parents[c[vi]].push_back(vi);
        }
        else {
            vg[parents[c[vi]].back()].push_back(vi);
            parents[c[vi]].push_back(vi);
        }
        sz[vi] = 1;
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs(ti, vi);
            sz[vi] += sz[ti];
        }
        parents[c[vi]].pop_back();
    };
    dfs(0, -1);
    rep(i, n) {
        ll sub = 0;
        queue<int> que;
        int val = sz[0];
        for (const int& ti : roots[i]) {
            que.push(ti);
            val -= sz[ti];
        }
        sub += val * (ll)(val+1) / 2;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            if (vg[vi].empty()) {
                for (const int& ti : g[vi]) if (ti != par[vi]) sub += sz[ti] * (ll)(sz[ti]+1) / 2;
                continue;
            }
            val = sz[vi] - 1;
            for (const int& ti : vg[vi]) {
                que.push(ti);
                val -= sz[ti];
            }
            sub += val * (ll)(val+1) / 2;
        }
        ll res = n * (ll)(n+1) / 2 - sub;
        cout << res << endl;
    }
    return 0;
}
