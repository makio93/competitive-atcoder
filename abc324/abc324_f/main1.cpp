// 解説AC

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
const double DINF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> b(m), c(m);
    vector<vector<pair<int, int>>> g(n);
    rep(i, m) {
        int ui, vi;
        cin >> ui >> vi >> b[i] >> c[i];
        --ui; --vi;
        g[ui].emplace_back(vi, i);
    }
    double lv = 0.0, rv = (double)(INF*2);
    while ((rv-lv)/rv > 1e-9) {
        double cv = (lv+rv) / 2.0;
        vector<double> dp(n, -DINF);
        dp[0] = 0.0;
        rep(i, n) for (const auto& [ti, ei] : g[i]) {
            int bi = b[ei], ci = c[ei];
            dp[ti] = max(dp[ti], dp[i]+bi-ci*cv);
        }
        if (dp[n-1] >= 0.0) lv = cv;
        else rv = cv;
    }
    printf("%.14f\n", lv);
    return 0;
}
