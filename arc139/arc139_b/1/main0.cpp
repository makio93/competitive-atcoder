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

const ll LINF = (ll)(2e18);

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
        ll nsqr = max(1LL, (ll)sqrt(n));
        ll res = LINF;
        if (n/a <= nsqr) {
            for (ll ai=0; ai<=n/a; ++ai) res = min(res, ai*y+(n-ai*a)/b*z+(n-ai*a)%b*x);
        }
        else {
            for (ll bi=0; bi<a; ++bi) {
                if (bi*b > n) break;
                res = min(res, bi*z+(n-bi*b)/a*y+(n-bi*b)%a*x);
            }
        }
        cout << res << endl;
    }
    return 0;
}
