// 学習3回目,自力AC

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

ll add(ll a, int d, int n) { return ((a + d) + (a + (ll)d * n)) * n / 2; }

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        ll aval = 0, bval = 0, mval = -LINF;
        rep(i, n) {
            ll lval = aval + add(bval, x[i], 1), rval = aval + add(bval, x[i], y[i]);
            mval = max({ mval, lval, rval });
            if (bval+x[i]>0 && bval+(ll)x[i]*y[i]<0) {
                int li = 1, ri = y[i];
                while (ri-li >= 3) {
                    int cl = li + (ri-li) / 3, cr = ri - (ri-li) / 3;
                    ll clval = aval + add(bval, x[i], cl), crval = aval + add(bval, x[i], cr);
                    if (clval <= crval) li = cl;
                    else ri = cr;
                }
                rep3(j, li, ri+1) mval = max(mval, aval + add(bval, x[i], j));
            }
            aval += add(bval, x[i], y[i]);
            bval += (ll)x[i] * y[i];
        }
        cout << mval << endl;
    }
    return 0;
}
