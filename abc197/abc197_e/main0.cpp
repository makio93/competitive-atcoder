// 本番AC

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
    v(int) x(n), c(n);
    rep(i, n) {
        cin >> x[i] >> c[i];
        c[i]--;
    }
    v(int) tlval(n, (int)(2e9)), trval(n, (int)(-2e9));
    rep(i, n) {
        tlval[c[i]] = min(tlval[c[i]], x[i]);
        trval[c[i]] = max(trval[c[i]], x[i]);
    }
    v(int) lval, rval;
    rep(i, n) if (tlval[i] != (int)(2e9)) lval.pb(tlval[i]);
    rep(i, n) if (trval[i] != (int)(-2e9)) rval.pb(trval[i]);
    int n2 = lval.size();
    v(v(ll)) dp(n2+1, v(ll)(2, (ll)(LINF)));
    dp[0][0] = dp[0][1] = 0;
    rep(i, n2) {
        if (i == 0) {
            dp[i+1][0] = llabs((ll)rval[0] - 0LL) + llabs((ll)lval[0]-rval[0]);
            dp[i+1][1] = llabs((ll)lval[0] - 0LL) + llabs((ll)rval[0]-lval[0]);
        }
        else {
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]+llabs((ll)rval[i]-lval[i-1])+llabs((ll)lval[i]-rval[i]));
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+llabs((ll)rval[i]-rval[i-1])+llabs((ll)lval[i]-rval[i]));
            dp[i+1][1] = min(dp[i+1][1], dp[i][1]+llabs((ll)lval[i]-rval[i-1])+llabs((ll)rval[i]-lval[i]));
            dp[i+1][1] = min(dp[i+1][1], dp[i][0]+llabs((ll)lval[i]-lval[i-1])+llabs((ll)rval[i]-lval[i]));
        }
    }
    ll ans = min(dp[n2][0]+llabs((ll)lval[n2-1]-0LL), dp[n2][1]+llabs((ll)rval[n2-1]-0LL));
    cout << ans << endl;
    return 0;
}
