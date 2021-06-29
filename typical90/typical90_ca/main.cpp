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
    vector<vector<ll>> sub(h, vector<ll>(w));
    rep(i, h) rep(j, w) {
        int ai;
        cin >> ai;
        sub[i][j] -= ai;
    }
    rep(i, h) rep(j, w) {
        int bi;
        cin >> bi;
        sub[i][j] += bi;
    }
	ll res = 0;
    rep(i, h-1) rep(j, w-1) {
        ll sval = sub[i][j];
        res += llabs(sval);
        rep(i2, 2) rep(j2, 2) sub[i+i2][j+j2] -= sval;
    }
    bool ok = true;
    rep(i, h) rep(j, w) if (sub[i][j] != 0LL) ok = false;
    if (ok) {
        cout << "Yes" << endl;
        cout << res << endl;
    }
    else cout << "No" << endl;
    return 0;
}
