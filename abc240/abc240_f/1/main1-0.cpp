// 復習1,解説AC

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

const ll LINF = (ll)(1e18);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        vector<ll> b(n+1), a(n+1);
        rep(i, n) b[i+1] = b[i] + (ll)y[i] * x[i];
        rep(i, n) a[i+1] = a[i] + y[i] * b[i] + (ll)y[i] * (y[i]+1) / 2 * x[i];
        ll res = -LINF;
        rep(i, n) {
            auto f = [&](int id1, int id2) -> ll { return a[id1] + id2 * b[id1] + (ll)id2 * (id2+1) / 2 * x[id1]; };
            if (x[i] >= 0) res = max({ res, f(i, 1), a[i+1] });
            else {
                int li = 1, ri = y[i];
                while (ri-li > 2) {
                    int cl = li + (ri-li) / 3, cr = ri - (ri-li) / 3;
                    if (f(i, cl) <= f(i, cr)) li = cl;
                    else ri = cr;
                }
                res = max({ res, f(i, li), f(i, ri), f(i, li+(ri-li)/2) });
            }
        }
        cout << res << endl;
    }
    return 0;
}
