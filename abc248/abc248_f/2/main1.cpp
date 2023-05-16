// 学習2回目,解説AC

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

int main() {
    int n;
    ll p;
    cin >> n >> p;
    vector<vector<ll>> dp(n*2, vector<ll>(2)), ndp;
    dp[0][0] = dp[1][1] = 1;
    rep3(i, 1, n) {
        ndp.assign(n*2, vector<ll>(2));
        rep(j, i+1) rep(a, 2) rep(b, 2) rep(c, 2) {
            if ((a+b+c) <= 1) ndp[j+a+b+c][0] = (ndp[j+a+b+c][0] + dp[j][0]) % p;
            else if ((a+b) <= 1) ndp[j+a+b+c][1] = (ndp[j+a+b+c][1] + dp[j][0]) % p;
            if ((a+b+c) == 0) ndp[j+a+b+c][0] = (ndp[j+a+b+c][0] + dp[j][1]) % p;
            else if ((a+b) == 0) ndp[j+a+b+c][1] = (ndp[j+a+b+c][1] + dp[j][1]) % p;
        }
        swap(ndp, dp);
    }
    rep3(i, 1, n) cout << dp[i][0] << (i<n-1?' ':'\n');
    return 0;
}
