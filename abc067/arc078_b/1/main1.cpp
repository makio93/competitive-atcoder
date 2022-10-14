// 学習1回目,解説AC

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
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    auto bfs = [&](vector<int>& dist, int si) -> void {
        queue<int> que;
        dist.resize(n, INF);
        que.push(si);
        dist[si] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (dist[ti] > ndi) {
                dist[ti] = ndi;
                que.push(ti);
            }
        }
    };
    vector<int> dist1, distn;
    bfs(dist1, 0);
    bfs(distn, n-1);
    int bcnt = 0;
    rep(i, n) if (dist1[i] <= distn[i]) ++bcnt;
    if (bcnt > n-bcnt) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
