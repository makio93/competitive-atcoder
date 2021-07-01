#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int am = 0, bm = 0;
    rep(i, n) {
        am = max(am, a[i]);
        bm = max(bm, b[i]);
    }
    vector<vector<int>> s(am+1, vector<int>(bm+1));
    rep(i, n) s[a[i]][b[i]]++;
    rep(i, am) rep(j, bm) s[i+1][j+1] += s[i][j+1] + s[i+1][j] - s[i][j];
    int res = 0;
    rep3(i, 1, am+1) rep3(j, 1, bm+1) {
        int i2 = max(0, i-k-1), j2 = max(0, j-k-1);
        res = max(res, s[i][j]-s[i2][j]-s[i][j2]+s[i2][j2]);
    }
    cout << res << endl;
    return 0;
}
