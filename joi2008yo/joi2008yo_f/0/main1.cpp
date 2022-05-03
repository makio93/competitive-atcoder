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
    rep(i, k) {
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            int ans = cost[a][b];
            if (ans == INF) cout << -1 << endl;
            else cout << ans << endl;
        }
        else {
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            rep(j, n) for (int h=j+1; h<n; ++h) {
                int val = INF;
                val = min(val, cost[j][c]+e+cost[d][h]);
                val = min(val, cost[j][d]+e+cost[c][h]);
                val = min(val, cost[j][h]);
                cost[j][h] = cost[h][j] = val;
            }
        }
    }
    return 0;
}
