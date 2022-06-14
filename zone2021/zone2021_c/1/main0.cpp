// 学習1回目,バチャ,自力AC

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
    vector<vector<int>> a(n, vector<int>(5));
    rep(i, n) rep(j, 5) cin >> a[i][j];
    int mval = 1;
    rep(i, n) rep(j, 5) mval = max(mval, a[i][j]);
    int li = 1, ri = mval+1;
    while (ri-li > 1) {
        int ci = (int)round(sqrt((ll)li*ri));
        vector<set<int>> tlst(1<<5);
        rep(i, n) {
            int tval = 0;
            rep(j, 5) if (a[i][j] >= ci) tval |= (1<<j);
            tlst[tval].insert(i);
        }
        bool ok = false;
        rep(i, n) {
            rep3(j, i+1, n) {
                int tval = 0;
                rep(i2, 5) if (max(a[i][i2], a[j][i2]) < ci) tval |= (1<<i2);
                rep(i2, (1<<5)) if ((tval&i2) == tval) {
                    if (!tlst[i2].empty()) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) li = ci;
        else ri = ci;
    }
    cout << li << endl;
    return 0;
}
