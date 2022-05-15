// 学習0回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    rep(i, d) cin >> t[i];
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<bool>> s(d, vector<bool>(n));
    rep(i, d) rep(j, n) {
        if (t[i]>=a[j] && t[i]<=b[j]) s[i][j] = true;
    }
    vector<vector<int>> dp(d, vector<int>(n));
    rep(i, d-1) rep(j, n) if (s[i][j]) {
        rep(k, n) if (s[i+1][k]) {
            dp[i+1][k] = max(dp[i+1][k], dp[i][j]+abs(c[j]-c[k]));
        }
    }
    int ans = -1;
    rep(i, n) ans = max(ans, dp[d-1][i]);
    cout << ans << endl;
    return 0;
}
