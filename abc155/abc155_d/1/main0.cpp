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

const ll LINF = (ll)(2e18);

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int mi = 0;
    while (mi<n && a[mi]<0) ++mi;
    if ((ll)mi*(n-mi) >= k) {
        ll lval = -LINF, rval = 0;
        while (rval-lval > 1) {
            ll cval = rval - (rval-lval) / 2, tcnt = 0;
            rep(i, mi) {
                ll tval = (abs(cval) + abs(a[i]) - 1) / abs(a[i]);
                tcnt += n - (lower_bound(a.begin()+mi, a.end(), tval) - a.begin());
            }
            if (tcnt < k) lval = cval;
            else rval = cval;
        }
        cout << rval << endl;
        return 0;
    }
    k -= (ll)mi * (n-mi);
    ll lval = -1, rval = LINF;
    while (rval-lval > 1) {
        ll cval = rval - (rval-lval) / 2, tcnt = 0;
        rep3(i, mi, n) {
            if (a[i] == 0) tcnt += n - i - 1;
            else {
                ll tval = cval / a[i];
                tcnt += (upper_bound(a.begin()+i+1, a.end(), tval) - a.begin()) - (i+1);
            }
        }
        rep(i, mi) {
            ll tval = -(cval / abs(a[i]));
            tcnt += i - (lower_bound(a.begin(), a.begin()+i, tval) - a.begin());
        }
        if (tcnt < k) lval = cval;
        else rval = cval;
    }
    cout << rval << endl;
    return 0;
}
