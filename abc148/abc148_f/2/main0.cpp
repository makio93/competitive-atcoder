// 学習2回目,自力AC

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
    int n, u, v;
    cin >> n >> u >> v;
    --u; --v;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    function<void(vector<int>&,int)> bfs = [&](vector<int>& dist, int si) {
        queue<int> que;
        dist[si] = 0;
        que.push(si);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (const int& ti : g[vi]) {
                if (dist[ti] <= ndi) continue;
                dist[ti] = ndi;
                que.push(ti);
            }
        }
    };
    vector<int> distu(n, INF), distv(n, INF);
    bfs(distu, u);
    bfs(distv, v);
    queue<int> que;
    vector<bool> visited(n);
    int res = 0;
    que.push(u);
    visited[u] = true;
    if ((int)(g[u].size()) > 1) res = max(res, distv[u]);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        for (const int& ti : g[vi]) if (!visited[ti] && (int)(g[ti].size())>1) {
            if (distu[ti] <= distv[ti]) {
                res = max(res, distv[ti]);
                visited[ti] = true;
            }
            if (distu[ti] < distv[ti]) que.push(ti);
        }
    }
    cout << res << endl;
    return 0;
}
