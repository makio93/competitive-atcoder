#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC、memo用配列を使わない遷移

const ll mod = (ll)(1e9) + 7;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), s(n+1);
    rep(i, n) cin >> a[i];
    rep(i, n) s[i+1] = s[i] + a[i];
    vector<vector<ll>> dp(n+2, vector<ll>(n+2));
    dp[1][0] = 1;
    rep(i, n-1) rep3r(j, 1, n+1) dp[j+1][s[i+1]%(j+1)] = (dp[j+1][s[i+1]%(j+1)] + dp[j][s[i+1]%j]) % mod;
    ll ans = 0;
    rep3(i, 1, n+1) ans = (ans + dp[i][s[n]%i]) % mod;
    cout << ans << endl;
    return 0;
}
