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
    vector<vector<int>> g(n, vector<int>(n, INF));
    rep(i, n) g[i][i] = 0;
    rep(i, k) {
        int op;
        cin >> op;
        if (op == 0) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            cout << ((g[a][b]!=INF)?g[a][b]:-1) << endl;
        }
        else {
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            if (g[c][d] <= e) continue;
            rep(i2, n) rep(j2, n) {
                g[i2][j2] = min(g[i2][j2], g[i2][c]+e+g[d][j2]);
                g[i2][j2] = min(g[i2][j2], g[i2][d]+e+g[c][j2]);
            }
        }
    }
    return 0;
}
