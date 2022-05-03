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
    vector<vector<int>> cost(n, vector<int>(n, INF));
    rep(i, n) cost[i][i] = 0;
    vector<vector<int>> dp = cost;
    rep(i, k) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            int ans = dp[a][b];
            if (ans == INF) cout << -1 << endl;
            else cout << ans << endl;
        }
        else {
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            if (e >= cost[c][d]) continue;
            cost[c][d] = cost[d][c] = e;
            dp = cost;
            rep(h, n) rep(j1, n) rep(j2, n) {
                dp[j1][j2] = min(dp[j1][j2], dp[j1][h]+dp[h][j2]);
            }
        }
    }
    return 0;
}
