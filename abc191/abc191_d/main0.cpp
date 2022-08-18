// 本番WA

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    ll x, y, r;
    double x2, y2, r2;
    cin >> x2 >> y2 >> r2;
    x = (ll)((x2) * (10000)); y = (ll)((y2) * (10000)); r = (ll)(r2 * (10000));
    x += (ll)(2e9); y += (ll)(2e9);
    ll llim = ((x-r+9999)/10000)*10000, rlim = x + r;
    ll cnt = 0;
    for (ll i=llim; i<=rlim; i+=10000) {
        ll dx = llabs(x-i);
        if (x == i) {
            ll ulim = (ll)(y+r)/10000*10000, dlim = (ll)(y-r+9999)/10000*10000;
            cnt += (ulim-dlim)/10000+1;
        }
        else {
            ll dy = (ll)(sqrtl(r*r-dx*dx)+DEPS);
            ll ulim = (ll)(y+dy)/10000*10000, dlim = (ll)(y-dy+9999)/10000*10000;
            cnt += (ulim-dlim)/10000+1;
        }
    }
    cout << cnt << endl;
    return 0;
}
