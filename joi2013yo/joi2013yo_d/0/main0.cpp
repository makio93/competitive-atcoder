// 学習0回目,自力AC

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
    vector<int> dp(n);
    rep(i, n) {
        if (a[i]>t[0] || b[i]<t[0]) dp[i] = -1;
    }
    rep3(i, 1, d) {
        vector<int> tmp(n);
        rep(j, n) {
            if (a[j]>t[i] || b[j]<t[i]) {
                tmp[j] = -1;
                continue;
            }
            rep(j2, n) {
                if (dp[j2] == -1) continue;
                tmp[j] = max(tmp[j], dp[j2]+abs(c[j]-c[j2]));
            }
        }
        swap(dp, tmp);
    }
    int ans = 0;
    rep(i, n) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
