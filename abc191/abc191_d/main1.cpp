// 解説AC

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

ll in() {
    double x;
    cin >> x;
    return (ll)(round(x*(1e4)));
}

bool ok(ll x, ll x2, ll y, ll y2, ll r) {
    return ((y2-y)*(y2-y) + (x2-x)*(x2-x) <= r*r);
}

ll cnt(ll x, ll y, ll r, ll lx=0, ll ly=0) {
    ll llim = x + lx * 10000LL;
    if (llim%10000LL != 0) {
        if (llim >= 0) llim = (llim + 9999LL) / 10000LL * 10000LL;
        else llim = llim / 10000LL * 10000LL;
    }
    ll res = 0, rlim = llim;
    for (ll i=(ll)(1e9)+50000LL; i>=y+ly*10000LL; i-=10000LL) {
        while (ok(x,rlim,y,i,r)) rlim += 10000LL;
        res += max(0LL, rlim-llim) / 10000LL;
    }
    return res;
}

int main(){
    ll x, y, r;
    x = in(); y = in(); r = in();
    x %= 10000; y %= 10000;
    ll lx = (x==0?1:0), ly = (y==0?1:0);
    ll ans = cnt(x, y, r);
    ans += cnt(-x, y, r, lx, 0LL);
    ans += cnt(x, -y, r, 0LL, ly);
    ans += cnt(-x, -y, r, lx, ly);
    cout << ans << endl;
    return 0;
}
