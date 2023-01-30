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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;
        y = min(y, a*x);
        z = min(z, b*x);
        if (z*a < y*b) {
            swap(a, b);
            swap(y, z);
        }
        ll lval = lcm(a, b), res = LINF;
        if (a >= b) {
            int alen = n / a;
            rep(i, lval/a+1) {
                if (i > alen) break;
                int aval = alen - i, bval = (n - aval * a) / b;
                res = min(res, aval*y+bval*z+(n-aval*a-bval*b)*x);
            }
        }
        else {
            int blen = n / b;
            rep(i, lval/b+1) {
                if (i > blen) break;
                int aval = (n - i * b) / a;
                res = min(res, aval*y+i*z+(n-aval*a-i*b)*x);
            }
        }
        cout << res << endl;
    }
    return 0;
}
