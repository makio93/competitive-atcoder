#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    int amax = 0;
    rep(i, n) rep(j, n) amax = max(amax, a[i][j]);
    int mid = k * k / 2;
    int ng = 0, ok = amax;
    while (ok-ng > 1) {
        int cen = (ng+ok) / 2;
        vector<vector<int>> sum(n+1, vector<int>(n+1));
        rep(i, n) rep(j, n) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (a[i][j]>cen ? 1 : 0);
        }
        bool app = false;
        rep3(i, k, n+1) rep3(j, k, n+1) {
            int scnt = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
            if (scnt <= mid) app = true;
        }
        if (app) ok = cen;
        else ng = cen;
    }
    cout << ok << endl;
    return 0;
}
