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

//

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, -1));
    vector<pair<int, int>> e(m);
    rep(i, m) {
        cin >> e[i].first >> e[i].second;
        e[i].first--; e[i].second--;
        g[e[i].first][e[i].second] = i;
    }
    vector<int> ememo(n, -1), dist(n, INF);
    queue<int> que;
    que.push(0);
    dist[0] = 0;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        int d = dist[v], nd = d + 1;
        rep(i, n) if (g[v][i] != -1) {
            if (dist[i] <= nd) continue;
            dist[i] = nd;
            que.push(i);
            ememo[i] = g[v][i];
        }
    }
    vector<int> ans;
    if (dist[n-1] == INF) ans = vector<int>(m, -1);
    else {
        ans = vector<int>(m, dist[n-1]);
        vector<int> path;
        int cur = n-1;
        while (cur != 0) {
            path.push_back(ememo[cur]);
            cur = e[ememo[cur]].first;
        }
        for (int ei : path) {
            g[e[ei].first][e[ei].second] = -1;
            vector<int> dist(n, INF);
            queue<int> que;
            dist[0] = 0;
            que.push(0);
            while (!que.empty()) {
                int v = que.front(); que.pop();
                int d = dist[v], nd = d + 1;
                rep(i, n) if (g[v][i] != -1) {
                    if (dist[i] <= nd) continue;
                    dist[i] = nd;
                    que.push(i);
                }
            }
            ans[ei] = (dist[n-1] == INF) ? -1 : dist[n-1];
            g[e[ei].first][e[ei].second] = ei;
        }
    }
    rep(i, m) cout << ans[i] << endl;
    return 0;
}
