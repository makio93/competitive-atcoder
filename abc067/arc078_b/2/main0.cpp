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
    function<void(vector<int>&,int)> bfs = [&](vector<int>& dist, int si) {
        queue<int> que;
        dist[si] = 0;
        que.push(si);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (const int& ti : g[vi]) if (dist[ti] == INF) {
                dist[ti] = ndi;
                que.push(ti);
            }
        }
    };
    vector<int> dist1(n, INF), distn(n, INF);
    bfs(dist1, 0);
    bfs(distn, n-1);
    int res = 0;
    rep(i, n) if (dist1[i] <= distn[i]) ++res;
    if (res > n-res) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
