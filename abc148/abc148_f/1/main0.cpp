// 学習1回目,自力AC

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
    vector<int> dist0(n, INF), dist1(n, INF);
    queue<int> que;
    dist0[v] = 0;
    que.push(v);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        int di = dist0[vi], ndi = di + 1;
        for (const int& ti : g[vi]) if (dist0[ti] > ndi) {
            dist0[ti] = ndi;
            que.push(ti);
        }
    }
    dist1[u] = 0;
    que.push(u);
    while (!que.empty()) {
        int vi = que.front(); que.pop();
        int di = dist1[vi], ndi = di + 1;
        for (const int& ti : g[vi]) if (dist0[ti]>ndi && dist1[ti]>ndi) {
            dist1[ti] = ndi;
            que.push(ti);
        }
    }
    int res = 0;
    rep(i, n) if (dist1[i] != INF) {
        if ((int)(g[i].size()) == 1) res = max(res, dist0[g[i][0]]);
        else res = max(res, dist0[i]);
    }
    cout << res << endl;
    return 0;
}
