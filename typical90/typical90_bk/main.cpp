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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> p(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> p[i][j];
    int res = 0;
    rep3(i, 1, (1<<h)) {
        vector<int> hid;
        rep(j, h) if ((i>>j) & 1) hid.push_back(j);
        unordered_map<int, int> pcnt;
        rep(j, w) {
            int jval = p[hid[0]][j];
            bool same = true;
            rep3(j2, 1, (int)(hid.size())) if (p[hid[j2]][j] != jval) {
                same = false;
                break;
            }
            if (same) pcnt[jval]++;
        }
        int mval = 0;
        for (auto pi : pcnt) mval = max(mval, pi.second);
        res = max(res, (int)(hid.size())*mval);
    }
    cout << res << endl;
    return 0;
}
