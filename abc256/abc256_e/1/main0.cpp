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

const int INF = (int)(1.5e9);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    rep(i, n) {
        cin >> x[i];
        x[i]--;
    }
    rep(i, n) cin >> c[i];
    vector<int> visited(n);
    auto dfs = [&](auto dfs, int& cost, int vi) -> int {
        visited[vi] = 1;
        int rval = -1;
        if (visited[x[vi]] == 0) {
            int tval = dfs(dfs, cost, x[vi]);
            if (tval != -1) {
                cost = min(cost, c[vi]);
                if (tval != vi) rval = tval;
            }
        }
        else if (visited[x[vi]] == 1) {
            cost = min(cost, c[vi]);
            rval = x[vi];
        }
        visited[vi] = -1;
        return rval;
    };
    ll res = 0;
    rep(i, n) if (visited[i] == 0) {
        int cost = INF;
        dfs(dfs, cost, i);
        if (cost != INF) res += cost;
    }
    cout << res << endl;
    return 0;
}
