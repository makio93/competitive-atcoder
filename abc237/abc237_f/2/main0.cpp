// 学習2回目,自力AC

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
    vector dp(n+1, vector(1<<m, 0LL));
    dp[0][0] = 1;
    rep(i, n) rep(j, 1<<m) rep(j2, m) {
        int ti = j ^ (((-(j>>j2))&(j>>j2)) << j2) ^ (1<<j2);
        dp[i+1][ti] = (dp[i+1][ti] + dp[i][j]) % mod;
    }
    ll res = 0;
    rep(i, 1<<m) if (__builtin_popcount(i) == 3) res = (res + dp[n][i]) % mod;
    cout << res << endl;
    return 0;
}
