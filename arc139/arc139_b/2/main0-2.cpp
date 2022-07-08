// 復習2回目,自力WA2

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

const ll LINF = (ll)(5e18);

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;
        y = min(y, x*a);
        z = min(z, x*b);
        if (a*z < b*y) {
            swap(a, b);
            swap(y, z);
        }
        ll lval = lcm(a, b), bval = 0, cval = n * x;
        if (n/lval > 0) {
            bval = LINF;
            rep(i, (int)(lval/a)+1) bval = min(bval, y*i+(lval-a*i)/b*z+(lval-a*i)%b*x);
            bval *= n / lval;
            n %= lval;
        }
        ll aval = LINF;
        rep(i, (int)(n/a)+1) aval = min(aval, y*i+(n-a*i)/b*z+(n-a*i)%b*x);
        ll res = min(cval, aval+bval);
        cout << res << endl;
    }
    return 0;
}
