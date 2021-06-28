#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n, q;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    int bcnt = 0;
    while (n > (1<<bcnt)) ++bcnt;
    vector<vector<int>> parent(bcnt+1, vector<int>(n, -1));
    vector<int> dord(n, -1), depth(n, -1);
    int dcnt = 0;
    function<void(int,int)> dfs = [&](int vi, int pi) {
        parent[0][vi] = pi;
        dord[vi] = dcnt; ++dcnt;
        if (pi == -1) depth[vi] = 0;
        else depth[vi] = depth[pi] + 1;
        for (int ti : g[vi]) if (ti != pi) dfs(ti, vi);
    };
    dfs(0, -1);
    rep(i, bcnt) rep(j, n) parent[i+1][j] = parent[i][parent[i][j]];
    cin >> q;
    rep(i, q) {
        int ki;
        cin >> ki;
        vector<int> vi(ki);
        rep(j, ki) {
            cin >> vi[j];
            vi[j]--;
        }
        sort(all(vi), [&](int a,int b){return (dord[a]<dord[b]);});
        function<int(int,int)> lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int d1 = depth[a] - depth[b];
            repr(i1, bcnt+1) if (d1 >= (1<<i1)) {
                a = parent[i1][a];
                d1 -= (1<<i1);
            }
            if (a == b) return a;
            repr(i1, bcnt+1) if (parent[i1][a] != parent[i1][b]) {
                a = parent[i1][a]; b = parent[i1][b];
            }
            return parent[0][a];
        };
        ll res = 0;
        rep(j, ki) res += depth[vi[j]] + depth[vi[(j+1)%ki]] - (ll)2 * depth[lca(vi[j],vi[(j+1)%ki])];
        res /= 2;
        cout << res << endl;
    }
    return 0;
}
