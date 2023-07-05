// 自力TLE(ヒント有)-1

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

int n;
v(v(bool)) g;
v(int) memo;
int dp(int s) {
    if (memo[s] != -1) return memo[s];
    if (s == 0) return (memo[s] = 0);
    v(int) vl;
    rep(i, n) if ((s>>i)&1) vl.pb(i);
    if (sz(vl) == 1) return (memo[s] = 1);
    bool comp = true;
    rep(i, sz(vl)) {
        rep2(j, i+1, sz(vl)-1) {
            if (!g[vl[i]][vl[j]]) comp = false;
            if (!comp) break;
        }
        if (!comp) break;
    }
    if (comp) return (memo[s] = 1);
    else {
        int m = sz(vl), res = n;
        rep2(i, 1, (1<<m)-2) {
            int t = s;
            rep(j, m) if ((i>>j)&1) t -= (1<<vl[j]);
            if (s==0 || s-t==0) continue;
            res = min(res, dp(t)+dp(s-t));
        }
        return (memo[s] = res);
    }
}

int main(){
    int m;
    cin >> n >> m;
    if (m == 0) {
        cout << n << endl;
        return 0;
    }
    g = v(v(bool))(n, v(bool)(n));
    rep(i, n) g[i][i] = true;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a][b] = g[b][a] = true;
    }
    memo = v(int)((1<<n), -1);
    memo[0] = 0;
    int ans = dp((1<<n)-1);
    cout << ans << endl;
    return 0;
}
