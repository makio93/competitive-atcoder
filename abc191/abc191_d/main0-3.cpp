// ヒント有,自力WA

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
    v(ll) ival(3);
    v(string) sval(3);
    rep(i1, 3) {
        cin >> sval[i1];
        size_t ppos = sval[i1].find('.'), blen = 0;
        if (ppos == string::npos) ival[i1] = stoll(sval[i1]) * (ll)(1e4);
        else {
            blen = (int)(sval[i1].length()) - (int)(ppos) - 1;
            rep2(i, blen, 3) sval[i1] += '0';
            ival[i1] = stoll(sval[i1].substr(0,(int)(ppos)))*(ll)(1e4);
            ival[i1] += (ival[i1]>=0?(stoll(sval[i1].substr((int)(ppos)+1))):(stoll(sval[i1].substr((int)(ppos)+1))*(-1)));
        }
    }
    ll x = ival[0], y = ival[1], r = ival[2];
    ll ans = 0, tpos = x / (ll)(1e4) * (ll)(1e4);
    if (x<0 && x%(ll)(1e4)!=0) tpos -= (ll)(1e4);
    for (ll i=tpos; i>=x-r; i-=(ll)(1e4)) {
        ll dx = llabs(i-x), dy = sqrt(r*r-dx*dx), ytop = y + dy, ybot = y - dy;
        ll yptop = (ytop>=0)?(ytop/(ll)(1e4)*(ll)(1e4)):((ytop+(ll)(1e4)-1)/(ll)(1e4)*(ll)(1e4));
        ll ypbot = (ybot<0)?(ybot/(ll)(1e4)*(ll)(1e4)):((ybot+(ll)(1e4)-1)/(ll)(1e4)*(ll)(1e4));
        if (yptop < ypbot) continue;
        ans += max(0LL, yptop-ypbot) / (ll)(1e4) + 1;
    }
    for (ll i=tpos+(ll)(1e4); i<=x+r; i+=(ll)(1e4)) {
        ll dx = llabs(i-x), dy = sqrt(r*r-dx*dx), ytop = y + dy, ybot = y - dy;
        ll yptop = (ytop>=0)?(ytop/(ll)(1e4)*(ll)(1e4)):((ytop+(ll)(1e4)-1)/(ll)(1e4)*(ll)(1e4));
        ll ypbot = (ybot<0)?(ybot/(ll)(1e4)*(ll)(1e4)):((ybot+(ll)(1e4)-1)/(ll)(1e4)*(ll)(1e4));
        if (yptop < ypbot) continue;
        ans += max(0LL, yptop-ypbot) / (ll)(1e4) + 1;
    }
    cout << ans << endl;
    return 0;
}
