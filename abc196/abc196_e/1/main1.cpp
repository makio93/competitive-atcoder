// 学習1回目,解説AC

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
    int n, q;
    cin >> n;
    vector<int> a(n), t(n);
    rep(i, n) cin >> a[i] >> t[i];
    ll l = -LINF, r = LINF, c = 0;
    rep(i, n) {
        if (t[i] == 1) {
            l += a[i];
            r += a[i];
            c += a[i];
        }
        else if (t[i] == 2) {
            r = max(r, (ll)a[i]);
            l = max(l, (ll)a[i]);
        }
        else {
            r = min(r, (ll)a[i]);
            l = min(l, (ll)a[i]);
        }
    }
    cin >> q;
    rep(i, q) {
        ll xi;
        cin >> xi;
        xi = min(r, max(l, xi+c));
        cout << xi << endl;
    }
    return 0;
}
