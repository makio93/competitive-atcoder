// 学習1回目,解説AC1

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
        unordered_set<int> bst;
        rep(i, n) {
            int bi = 0;
            rep(j, 5) if (a[i][j] >= ci) bi |= 1<<j;
            bst.insert(bi);
        }
        bool ok = false;
        for (int i1 : bst) for (int i2 : bst) for (int i3 : bst) if ((i1|i2|i3) == (1<<5)-1) ok = true;
        if (ok) li = ci;
        else ri = ci;
    }
    cout << li << endl;
    return 0;
}
