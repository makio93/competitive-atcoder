// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        g[x-1][y-1] = true;
        g[y-1][x-1] = true;
    }
    int ans = 0;
    rep(i, n) {
        int cnt = 1;
        vector<bool> t(n, false);
        rep(j, n) {
            if (i == j) continue;
            t[j] = true;
            rep(k, j) {
                if (!t[k]) continue;
                if (!g[j][k]) t[j] = false;
            }
            if (!g[j][i]) t[j] = false;
            if (t[j]) ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
