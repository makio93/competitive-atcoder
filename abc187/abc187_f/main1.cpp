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

int main(){
    int n, m;
    cin >> n >> m;
    v(int) g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a] |= 1<<b;
        g[b] |= 1<<a;
    }
    v(int) dp(1<<n, INF);
    dp[0] = 1;
    rep(i, n) rep(j, (1<<i)) if (dp[j] == 1) {
        if ((g[i] & j) == j) dp[(1<<i)|j] = 1;
    }
    rep(i, (1<<n)) if (dp[i] != 1) rep2r(j, 0, i-1) {
        j &= i;
        dp[i] = min(dp[i], dp[j]+dp[j^i]);
    }
    cout << dp[(1<<n)-1] << endl; 
    return 0;
}
