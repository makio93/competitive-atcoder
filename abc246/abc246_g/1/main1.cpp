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
    vector<int> a(n);
    rep3(i, 1, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ui, vi;
        cin >> ui >> vi;
        --ui; --vi;
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    int li = 0, ri = *max_element(all(a)) + 1;
    while (ri-li > 1) {
        int ci = li + (ri-li) / 2;
        vector<int> dp(n, -1);
        function<void(int,int)> dfs = [&](int vi, int pi) {
            dp[vi] = 0;
            for (const int& ti : g[vi]) if (ti != pi) {
                dfs(ti, vi);
                dp[vi] += dp[ti];
            }
            dp[vi] = max(0, dp[vi]-1) + (a[vi] >= ci ? 1 : 0);
        };
        dfs(0, -1);
        if (dp[0] > 0) li = ci;
        else ri = ci;
    }
    cout << li << endl;
    return 0;
}
