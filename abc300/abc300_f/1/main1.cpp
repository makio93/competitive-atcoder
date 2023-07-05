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
    int n, m;
    ll k;
    string s;
    cin >> n >> m >> k >> s;
    int xlen = count(all(s), 'x');
    if (xlen*(ll)m == k) {
        cout << (n*(ll)m) << endl;
        return 0;
    }
    vector<int> xlst(n+1);
    rep(i, n) if (s[i] == 'x') xlst[i+1] = 1;
    rep(i, n) xlst[i+1] += xlst[i];
    function<ll(ll)> calc = [&](ll x) {
        ll rval = x / n * xlst[n];
        rval += xlst[x%n];
        return rval;
    };
    ll res = 0;
    rep(i, n) {
        ll lval = i, rval = n * (ll)m, lcnt = calc((ll)i);
        while (rval-lval > 1) {
            ll cval = lval + (rval-lval) / 2;
            if (calc(cval)-lcnt <= k) lval = cval;
            else rval = cval;
        }
        res = max(res, lval-i);
    }
    cout << res << endl;
    return 0;
}
