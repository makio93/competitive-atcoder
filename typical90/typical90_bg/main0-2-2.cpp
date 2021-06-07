#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 小課題1まで解く解法、自力、小課題1まで正解

const int INF = (int)(1e9);

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    rep(i, m) {
        int xi, yi;
        cin >> xi >> yi;
        --xi; --yi;
        g[xi].push_back(yi);
    }
    vector<unordered_map<int, vector<int>>> qlst(n);
    rep(i, q) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        qlst[ai][bi].push_back(i);
    }
    vector<bool> ans(q);
    rep(i, n) {
        if (qlst[i].empty()) continue;
        vector<int> dist(n, INF);
        queue<int> que;
        que.push(i);
        dist[i] = 0;
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int d = dist[v], nd = d + 1;
            rep(j, (int)(g[v].size())) {
                int t = g[v][j];
                if (dist[t] <= nd) continue;
                que.push(t);
                dist[t] = nd;
            }
        }
        for (auto p : qlst[i]) {
            int t = p.first; auto ql = p.second;
            if (dist[t] == INF) continue;
            rep(j, (int)(ql.size())) ans[ql[j]] = true;
        }
    }
    rep(i, q) cout << (ans[i] ? "Yes" : "No") << endl;
    return 0;
}
