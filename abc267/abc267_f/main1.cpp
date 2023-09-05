// 解説AC

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
    cin >> q;
    vector<int> u(q), k(q);
    rep(i, q) {
        cin >> u[i] >> k[i];
        u[i]--;
    }
    function<int(int)> f0 = [&](int si) {
        vector<int> dist(n, INF);
        queue<int> que;
        dist[si] = 0;
        que.push(si);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (dist[ti] > ndi) {
                dist[ti] = ndi;
                que.push(ti);
            }
        }
        return max_element(all(dist)) - dist.begin();
    };
    int d1 = f0(0), d2 = f0(d1);
    vector<vector<pair<int, int>>> kq(n);
    rep(i, q) kq[u[i]].emplace_back(k[i], i);
    vector<int> res(q, -1);
    function<void(vector<int>&, int, int, int)> dfs = [&](vector<int>& lst, int vi, int pi, int di) {
        lst.push_back(vi);
        for (const auto& [ki, qi] : kq[vi]) {
            if (di-ki < 0 || res[qi] != -1) continue;
            res[qi] = lst[di-ki] + 1;
        }
        for (const int& ti : g[vi]) if (ti != pi) dfs(lst, ti, vi, di+1);
        lst.pop_back();
    };
    vector<int> tlst;
    dfs(tlst, d1, -1, 0);
    dfs(tlst, d2, -1, 0);
    rep(i, q) cout << res[i] << endl;
    return 0;
}
