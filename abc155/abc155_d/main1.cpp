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

const ll LINF = (ll)(1.5e18);

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
    ll nmul = (ll)nlen * plen, zmul = (ll)zlen * (zlen-1) / 2 + (ll)zlen * (nlen + plen), res = 0;
    if (k <= nmul) {
        sort(all(neg));
        sort(all(pos));
        ll lval = -LINF, rval = 0;
        while (rval-lval > 1) {
            ll cval = rval - (rval-lval) / 2, tcnt = 0;
            int id = 0;
            rep(i, plen) {
                while (id<nlen && (ll)neg[id]*pos[i]<=cval) ++id;
                tcnt += id;
            }
            if (tcnt >= k) rval = cval;
            else lval = cval;
        }
        res = rval;
    }
    else if (k > nmul+zmul) {
        k -= nmul + zmul;
        sort(all(pos));
        rep(i, nlen) neg[i] = -neg[i];
        sort(all(neg));
        ll lval = 0, rval = LINF;
        while (rval-lval > 1) {
            ll cval = rval - (rval-lval) / 2, tcnt = 0;
            int id = 0;
            repr(i, plen) {
                while (id<plen && (ll)pos[id]*pos[i]<=cval) ++id;
                tcnt += id - (i <= id-1 ? 1 : 0);
            }
            id = 0;
            repr(i, nlen) {
                while (id<nlen && (ll)neg[id]*neg[i]<=cval) ++id;
                tcnt += id - (i <= id-1 ? 1 : 0);
            }
            if (tcnt/2 >= k) rval = cval;
            else lval = cval;
        }
        res = rval;
    }
    cout << res << endl;
    return 0;
}
