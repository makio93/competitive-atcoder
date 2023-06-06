// 解説AC

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
    ll lval = -LINF - 1, rval = LINF + 1;
    while (rval-lval > 1) {
        ll cval = lval + (rval-lval) / 2;
        bool ok = [&]{
            ll total = 0;
            rep(i, n) {
                if (a[i] < 0) {
                    int li = -1, ri = n;
                    while (ri-li > 1) {
                        int ci = li + (ri-li) / 2;
                        if (a[i]*a[ci] < cval) ri = ci;
                        else li = ci;
                    }
                    total += n - ri;
                }
                else {
                    int li = -1, ri = n;
                    while (ri-li > 1) {
                        int ci = li + (ri-li) / 2;
                        if (a[i]*a[ci] < cval) li = ci;
                        else ri = ci;
                    }
                    total += li + 1;
                }
                if (a[i]*a[i] < cval) --total;
            }
            return total / 2 < k;
        }();
        if (ok) lval = cval;
        else rval = cval;
    }
    cout << lval << endl;
    return 0;
}
