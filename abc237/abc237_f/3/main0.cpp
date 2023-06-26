// 学習3回目,自力AC

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

const ll mod = 998244353LL;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(1<<m));
    rep(i, m) dp[0][1<<i] = 1;
    rep3(i, 1, n) rep(j, 1<<m) rep(j2, m) {
        int ti = j >> j2, li = (ti & -ti) << j2, bi = j ^ li ^ (1<<j2);
        dp[i][bi] = (dp[i][bi] + dp[i-1][j]) % mod;
    }
    ll res = 0;
    rep(i, 1<<m) if (__builtin_popcount(i) == 3) res = (res + dp[n-1][i]) % mod;
    cout << res << endl;
    return 0;
}
