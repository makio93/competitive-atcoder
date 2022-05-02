// 復習1,自力AC

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        vector<ll> b(n+1);
        rep(i, n) b[i+1] += b[i] + (ll)y[i] * x[i];
        ll res = x[0], val = 0;
        rep(i, n) {
            ll nval = val + (b[i]+x[i]+b[i+1]) * y[i] / 2;
            if (b[i]+x[i]>=0 && b[i+1]<0) {
                int li = 1, ri = y[i];
                while (ri-li >= 2) {
                    int ci = li + (ri-li) / 2;
                    ll cval = b[i] + (ll)x[i] * ci;
                    if (cval >= 0) li = ci;
                    else ri = ci;
                }
                res = max({ res, val+(b[i]+x[i]+b[i]+(ll)x[i]*li)*li/2, val+(b[i]+x[i]+b[i]+(ll)x[i]*ri)*ri/2 });
            }
            res = max({ res, val+b[i]+x[i], nval });
            val = nval;
        }
        cout << res << endl;
    }
    return 0;
}
