// 学習1回目,解説AC4

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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    ll lval = 0, rval = LINF;
    auto check = [&](ll cval) -> bool {
        int cnt = 0;
        rep(i, x) rep(j, y) rep(i2, z) {
            if (a[i]+b[j]+c[i2] < cval) break;
            ++cnt;
            if (cnt >= k) return true;
        }
        return false;
    };
    while (rval-lval > 1) {
        ll cval = lval + (rval - lval) / 2;
        if (check(cval)) lval = cval;
        else rval = cval;
    }
    vector<ll> res;
    rep(i, min(k, x)) rep(j, min(k, y)) rep(i2, min(k, z)) {
        if (a[i]+b[j]+c[i2] <= lval) break;
        res.push_back(a[i]+b[j]+c[i2]);
    }
    while ((int)(res.size()) < k) res.push_back(lval);
    sort(res.rbegin(), res.rend());
    rep(i, k) cout << res[i] << endl;
    return 0;
}
