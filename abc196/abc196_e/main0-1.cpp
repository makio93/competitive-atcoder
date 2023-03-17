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
    int n;
    cin >> n;
    v(ll) a(n);
    v(int) t(n);
    rep(i, n) cin >> a[i] >> t[i];
    ll u = (ll)(1e15)+5, d = (ll)(-1e15)-5;
    rep(i, n) {
        if (t[i] == 1) u += a[i];
        else if (t[i] == 2) u = max(u, (ll)(a[i]));
        else if (t[i] == 3) u = min(u, (ll)(a[i]));
    }
    rep(i, n) {
        if (t[i] == 1) d += a[i];
        else if (t[i] == 2) d = max(d, (ll)(a[i]));
        else if (t[i] == 3) d = min(d, (ll)(a[i]));
    }
    ll c = (u + d) / 2;
    rep(i, n) {
        if (t[i] == 1) c += a[i];
        else if (t[i] == 2) c = max(c, (ll)(a[i]));
        else if (t[i] == 3) c = min(c, (ll)(a[i]));
    }
    ll sub = c - (u+d)/2;
    int q;
    cin >> q;
    v(ll) x(q);
    rep(i, q) cin >> x[i];
    rep(i, q) {
        if (x[i] >= u) cout << u << endl;
        else if (x[i] <= d) cout << d << endl;
        else {
            cout << (x[i]+sub) << endl;
        }
    }
    return 0;
}
