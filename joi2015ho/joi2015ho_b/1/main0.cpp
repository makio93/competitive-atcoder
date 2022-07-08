// 復習1回目,自力AC

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
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n*2-1, vector<ll>(n*2-1));
    if (n%2 == 1) rep(i, 2*n-1) dp[i][i] = a[i%n];
    rep3(k, 1, n) for (int i=0; i+k<n*2-1; ++i) {
        int ri = i + k;
        if ((n-k)%2 == 1) dp[i][ri] = max(dp[i][ri-1]+a[ri%n], dp[i+1][ri]+a[i%n]);
        else dp[i][ri] = a[i%n] >= a[ri%n] ? dp[i+1][ri] : dp[i][ri-1];
    }
    ll res = 0;
    rep(i, n) res = max(res, dp[i][i+n-1]);
    cout << res << endl;
    return 0;
}
