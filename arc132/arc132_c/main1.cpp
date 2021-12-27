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

// 解説AC,自力実装

using mint = modint998244353;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        if (a[i] != -1) a[i]--;
    }
    vector<vector<mint>> dp(n+1, vector<mint>(1<<(2*d+1)));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, (1<<(2*d+1))) {
            if (i-d < 0) { if (((1<<(d-i))-1)&j) continue; }
            if (i-d>=0 && (!(j&1))) { if (a[i]==-1 || (a[i]!=-1&&a[i]==i-d)) dp[i+1][(j>>1)] += dp[i][j]; }
            else {
                if (a[i] != -1) { if (!((j>>(a[i]-i+d))&1)) dp[i+1][((j|(1<<(a[i]-i+d)))>>1)] += dp[i][j]; }
                else rep3(j2, max(1,d-i), 2*d+1) { if (!((j>>j2)&1)) dp[i+1][((j|(1<<j2))>>1)] += dp[i][j]; }
            }
        }
    }
    mint res = 0;
    rep(i, (1<<(2*d+1))) if (!(i&(((1<<(d+1))-1)<<d))) res += dp[n][i];
    cout << res.val() << endl;
    return 0;
}
