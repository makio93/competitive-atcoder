// 学習3回目,解説AC

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

ll calc(ll a, ll b, int d, int n) { return a + ((b + d) + (b + (ll)d * n)) * n / 2; }

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
            if (x[i] >= 0) mval = max({ mval, calc(aval, bval, x[i], 1), calc(aval, bval, x[i], y[i]) });
            else {
                int li = 1, ri = y[i];
                while (ri-li >= 1) {
                    int mi = li + (ri-li) / 2;
                    if (calc(aval, bval, x[i], mi) <= calc(aval, bval, x[i], mi+1)) li = mi + 1;
                    else ri = mi;
                }
                mval = max(mval, calc(aval, bval, x[i], li));
            }
            aval = calc(aval, bval, x[i], y[i]);
            bval += (ll)x[i] * y[i];
        }
        cout << mval << endl;
    }
    return 0;
}
