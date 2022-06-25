// 復習2回目,自力AC

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

const ll LINF = (ll)(4e18);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        vector<ll> b(n+1), a(n+1);
        rep(i, n) b[i+1] = b[i] + (ll)x[i] * y[i];
        ll res = -LINF;
        rep(i, n) {
            a[i+1] = a[i] + b[i] * y[i] + (ll)x[i] * y[i] * (y[i]+1) / 2;
            auto calc = [&](int id) -> ll {
                return a[i] + b[i] * id + (ll)x[i] * id * (id+1) / 2;
            };
            if (x[i] >= 0) res = max({ res, calc(1), calc(y[i]) });
            else {
                int li = 1, ri = y[i];
                while (ri-li > 1) {
                    if (ri-li == 2) {
                        int ci = li + (ri-li) / 2;
                        if (calc(li) <= calc(ri)) li = ci;
                        else ri = ci;
                    }
                    else {
                        int cl = li + (ri-li) / 3, cr = ri - (ri-li) / 3;
                        if (calc(cl) <= calc(cr)) li = cl;
                        else ri = cr;
                    }
                }
                res = max({ res, calc(1), calc(y[i]), calc(li), calc(ri) });
            }
        }
        cout << res << endl;
    }
    return 0;
}
