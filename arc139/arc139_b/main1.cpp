// 復習2回目,解説AC

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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

const ll LINF = (ll)(8e18);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;
        y = min(y, x*a);
        z = min(z, x*b);
        if (y*b > z*a) {
            swap(a, b);
            swap(y, z);
        }
        ll res = numeric_limits<ll>::max();
        if (n/a < a-1) for (ll i=0; i<=n/a; ++i) res = min(res, i*y+(n-i*a)/b*z+(n-i*a)%b*x);
        else {
            for (ll i=0; i<a; ++i) {
                if (i*b > n) break;
                res = min(res, i*z+(n-i*b)/a*y+(n-i*b)%a*x);
            }
        }
        cout << res << endl;
    }
    return 0;
}
