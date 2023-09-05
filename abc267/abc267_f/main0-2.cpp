// 自力AC

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
    int d1 = f0(0), d2 = f0(d1), lg = (int)(ceil(log(n) / log(2))) + 1;
    function<void(vector<vector<int>>&, int)> f1 = [&](vector<vector<int>>& dp, int si) {
        dp.assign(lg, vector<int>(n, -1));
        function<void(int, int)> dfs = [&](int vi, int pi) {
            dp[0][vi] = pi;
            for (const int& ti : g[vi]) if (ti != pi) dfs(ti, vi);
        };
        dfs(si, -1);
        rep(i, lg-1) rep(j, n) if (dp[i][j] != -1) dp[i+1][j] = dp[i][dp[i][j]];
    };
    vector<vector<int>> dp1, dp2;
    f1(dp1, d1);
    f1(dp2, d2);
    cin >> q;
    function<int(vector<vector<int>>&, int, int)> f2 = [&](vector<vector<int>>& dp, int ui, int ki) {
        rep(i, lg) {
            if (ki&1) ui = dp[i][ui];
            ki /= 2;
            if (ui == -1) return ui;
        }
        return ui;
    };
    rep(i, q) {
        int ui, ki;
        cin >> ui >> ki;
        --ui;
        int res = f2(dp1, ui, ki);
        if (res != -1) {
            cout << (res+1) << endl;
            continue;
        }
        res = f2(dp2, ui, ki);
        if (res != -1) cout << (res+1) << endl;
        else cout << res << endl;
    }
    return 0;
}
