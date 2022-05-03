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

const ll LINF = (ll)(1e18);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;
        y = min(y, a*x);
        z = min(z, b*x);
        if (y*b > z*a) {
            swap(y, z);
            swap(a, b);
        }
        ll res = LINF;
        if (n/a < a) {
            auto acalc = [&](ll aval) -> ll {
                ll sub = n - aval * a;
                return aval*y + sub/b*z + sub%b*x;
            };
            for (ll c=0; c<=n/a; ++c) res = min(res, acalc(c));
        }
        else {
            auto bcalc = [&](ll bval) -> ll {
                ll sub = n - bval * b;
                return bval*z + sub/a*y + sub%a*x;
            };
            for (ll c=0; c<=a-1; ++c) {
                if (n-c*b < 0) break;
                res = min(res, bcalc(c));
            }
        }
        cout << res << endl;
    }
    return 0;
}
