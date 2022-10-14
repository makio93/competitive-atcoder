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
    vector<queue<int>> que(2);
    vector<int> visited(n, -1);
    que[0].push(0);
    visited[0] = 0;
    que[1].push(n-1);
    visited[n-1] = 1;
    while (!que[0].empty() || !que[1].empty()) {
        rep(i, 2) {
            int ql = que[i].size();
            rep(j, ql) {
                int vi = que[i].front(); que[i].pop();
                for (const int& ti : g[vi]) if (visited[ti] == -1) {
                    visited[ti] = i;
                    que[i].push(ti);
                }
            }
        }
    }
    int bcnt = count(all(visited), 0);
    if (bcnt > n-bcnt) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
