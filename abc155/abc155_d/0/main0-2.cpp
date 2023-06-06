// 自力AC

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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> neg, zero, pos;
    rep(i, n) {
        if (a[i] < 0) neg.push_back(a[i]);
        else if (a[i] == 0) zero.push_back(a[i]);
        else pos.push_back(a[i]);
    }
    int nlen = neg.size(), zlen = zero.size(), plen = pos.size();
    ll res = 0;
    if (k <= (ll)nlen*plen) {
        sort(all(neg)), sort(all(pos));
        ll lval = -LINF, rval = 0, nval = -LINF;
        bool just = false;
        while (rval-lval > 1) {
            ll cval = lval + (rval-lval) / 2, tcnt = 0, tnval = -LINF;
            rep(i, plen) {
                ll tval = -((abs(cval)+pos[i]-1) / pos[i]);
                int id = upper_bound(all(neg), tval) - neg.begin();
                tcnt += id;
                if (id-1 >= 0) tnval = max(tnval, (ll)neg[id-1]*pos[i]);
            }
            if (tcnt <= k) {
                lval = cval;
                nval = tnval;
                if (tcnt == k) just = true;
            }
            else {
                rval = cval;
                if (rval-1==lval && !just) nval = tnval;
            }
        }
        res = nval;
    }
    else if (k <= (ll)nlen*plen+(ll)zlen*(zlen-1)/2+(ll)zlen*(nlen+plen)) res = 0;
    else {
        k -= (ll)nlen*plen+(ll)zlen*(zlen-1)/2+(ll)zlen*(nlen+plen);
        sort(all(pos));
        rep(i, nlen) neg[i] *= -1;
        sort(all(neg));
        ll lval = 0, rval = LINF, nval = 0;
        bool just = false;
        while (rval-lval > 1) {
            ll cval = lval + (rval-lval) / 2, tcnt = 0, tnval = 0;
            rep(i, plen) {
                ll tval = cval / pos[i];
                int id = upper_bound(pos.begin(), pos.begin()+i, tval)-pos.begin();
                tcnt += id;
                if (id-1 >= 0) {
                    tnval = max(tnval, (ll)pos[id-1]*pos[i]);
                }
            }
            rep(i, nlen) {
                ll tval = cval / neg[i];
                int id = upper_bound(neg.begin(), neg.begin()+i, tval) - neg.begin();
                tcnt += id;
                if (id-1 >= 0) {
                    tnval = max(tnval, (ll)neg[id-1]*neg[i]);
                }
            }
            if (tcnt <= k) {
                lval = cval;
                nval = tnval;
                if (tcnt == k) just = true;
            }
            else {
                rval = cval;
                if (rval-1==lval && !just) nval = tnval;
            }
        }
        res = nval;
    }
    cout << res << endl;
    return 0;
}
