// 復習1回目,解説AC2

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

const int INF = (int)(1e9);

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(40, vector<ll>(n));
    rep(i, n) dp[0][i] = a[i];
    rep(i, 39) rep(j, n) dp[i+1][j] = dp[i][j] + dp[i][(j+dp[i][j])%n];
    ll res = 0;
    rep(i, 40) if ((k>>i)&1) res += dp[i][(int)(res%n)];
    cout << res << endl;
    return 0;
}
