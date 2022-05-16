// 復習1回目,自力AC

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
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    vector<vector<bool>> used(n, vector<bool>(n));
    rep(i, n) used[i][i] = true;
    int res = 0;
    rep(i, n) rep(j, n) if (!used[i][j]) {
        int dy = y[j] - y[i], dx = x[j] - x[i];
        vector<int> ids;
        ids.push_back(i);
        ids.push_back(j);
        int cnt = 2;
        rep(i2, n) if (!used[i][i2] && i!=i2 && j!=i2) {
            int dy2 = y[i2] - y[i], dx2 = x[i2] - x[i];
            if ((ll)dy*dx2 == (ll)dx*dy2) {
                ++cnt;
                ids.push_back(i2);
            }
        }
        if (cnt >= k) ++res;
        int m = ids.size();
        rep(i2, m) rep3(j2, i2+1, m) used[ids[i2]][ids[j2]] = used[ids[j2]][ids[i2]] = true;
    }
    cout << res << endl;
    return 0;
}
