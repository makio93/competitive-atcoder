// 学習2回目,自力AC

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
    int mval = 0;
    rep(i, n) rep(j, 5) mval = max(mval, a[i][j]);
    int li = 0, ri = mval + 1;
    while (ri-li > 1) {
        int ci = li + (ri-li) / 2;
        vector<bool> exist1(1<<5), exist2(1<<5);
        rep(i, n) {
            int bi = 0;
            rep(j, 5) if (a[i][j] >= ci) bi |= 1<<j;
            exist1[bi] = true;
        }
        rep(i, n) rep3(j, i+1, n) {
            int bi = 0;
            rep(i2, 5) if (max(a[i][i2], a[j][i2]) >= ci) bi |= 1<<i2;
            exist2[bi] = true;
        }
        bool ok = false;
        rep(i, 1<<5) {
            rep(j, 1<<5) if ((i|j)==(1<<5)-1 && exist1[i] && exist2[j]) {
                ok = true;
                break;
            }
            if (ok) break;
        }
        if (ok) li = ci;
        else ri = ci;
    }
    cout << li << endl;
    return 0;
}
