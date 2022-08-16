// 学習1回目,解説AC

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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, LINF)));
    dp[0][0][0] = a[0];
    dp[0][1][1] = 0;
    rep3(i, 1, n) rep(j, 2) rep(i2, 2) rep(j2, 2) {
        dp[i][j][i2] = min(dp[i][j][i2], dp[i-1][j][j2]+(i2==0?a[i]:0)+(i2==j2?b[i-1]:0));
    }
    ll res = LINF;
    rep(i, 2) rep(j, 2) res = min(res, dp[n-1][i][j]+(j==i?b[n-1]:0));
    cout << res << endl;
    return 0;
}
