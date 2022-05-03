// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> g(n);
    rep(i, k) {
        int x;
        cin >> x;
        if (x == 0) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            vector<int> dist(n, INF);
            q.emplace(0, a);
            dist[a] = 0;
            while (!q.empty()) {
                auto p = q.top(); q.pop();
                int d = p.first, v = p.second;
                if (d > dist[v]) continue;
                for (auto to : g[v]) {
                    int nv = to.first, nd = d + to.second;
                    if (nd >= dist[nv]) continue;
                    q.emplace(nd, nv);
                    dist[nv] = nd;
                }
            }
            cout << ((dist[b]!=INF)?dist[b]:-1) << endl;
        }
        else {
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            g[c].emplace_back(d, e);
            g[d].emplace_back(c, e);
        }
    }
    return 0;
}
