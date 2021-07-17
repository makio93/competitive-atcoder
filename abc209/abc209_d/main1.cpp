#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    queue<int> que;
    vector<int> dist(n, INF);
    que.push(0);
    dist[0] = 0;
    while (!que.empty()) {
        int v = que.front(); que.pop();
        int d = dist[v], nd = d + 1;
        for (int t : g[v]) {
            if (dist[t] <= nd) continue;
            que.push(t);
            dist[t] = nd;
        }
    }
    rep(i, q) {
        int ci, di;
        cin >> ci >> di;
        --ci; --di;
        if (dist[ci]%2 == dist[di]%2) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
    return 0;
}
