// 

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
    vector<pair<int, int>> xy(n);
    rep(i, n) xy[i] = { x[i], y[i] };
    sort(all(xy));
    rep(i, n) {
        x[i] = xy[i].first;
        y[i] = xy[i].second;
    }
    set<pair<int, int>> used;
    int res = 0;
    rep(i, n) rep3(j, i+1, n) {
        if (used.find({ i, j }) != used.end()) continue;
        vector<int> plst = { i, j };
        int dy = y[j]-y[i], dx = x[j]-x[i], kcnt = 2;
        rep3(j2, j+1, n) {
            int py = y[j2]-y[i], px = x[j2]-x[i];
            if (dx*py == dy*px) {
                plst.push_back(j2);
                ++kcnt;
            }
        }
        if (kcnt >= k) ++res;
        int plen = plst.size();
        rep(i2, plen) rep3(j2, i2+1, plen) used.emplace(plst[i2], plst[j2]);
    }
    cout << res << endl;
    return 0;
}
