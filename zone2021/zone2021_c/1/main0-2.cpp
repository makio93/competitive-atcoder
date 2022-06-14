// 学習1回目,自力AC2

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
    int li = 0, ri = mval+1;
    while (ri-li > 1) {
        int ci = li + (ri-li) / 2;
        vector<int> exist(1<<5), blst;
        rep(i, n) {
            int bi = 0;
            rep(j, 5) if (a[i][j] >= ci) bi |= 1<<j;
            exist[bi]++;
        }
        rep(i, 1<<5) rep(j, min(3,exist[i])) blst.push_back(i);
        int m = blst.size();
        bool ok = false;
        rep(i1, m) rep3(i2, i1+1, m) rep3(i3, i2+1, m)
            if ((blst[i1]|blst[i2]|blst[i3]) == (1<<5)-1) ok = true;
        if (ok) li = ci;
        else ri = ci;
    }
    cout << li << endl;
    return 0;
}
