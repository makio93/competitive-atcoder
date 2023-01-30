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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;
        y = min(y, a*x), z = min(z, b*x);
        if (z*a < y*b) swap(a, b), swap(y, z);
        ll res = LINF;
        if (n/a <= a-1) {
            rep(i, n/a+1) {
                int j = (n - i * a) / b;
                res = min(res, i*y+j*z+(n-i*a-j*b)*x);
            }
        }
        else {
            rep(i, n/b+1) {
                if (i >= a) break;
                int j = (n - i * b) / a;
                res = min(res, j*y+i*z+(n-j*a-i*b)*x);
            }
        }
        cout << res << endl;
    }
    return 0;
}
