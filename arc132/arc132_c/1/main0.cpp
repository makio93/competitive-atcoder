// 復習1,自力AC

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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        if (a[i] != -1) a[i]--;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(1<<(d*2+1)));
    dp[0][(1<<(d+1))-1] = 1;
    rep(i, n) {
        for (int j=1; j<(1<<(d*2+1)); j+=2) {
            int nj = j >> 1;
            if (a[i] == -1) {
                rep(j2, d*2+1) if (!((nj>>j2)&1)) dp[i+1][nj|(1<<j2)] = (dp[i+1][nj|(1<<j2)] + dp[i][j]) % mod;
            }
            else {
                if (!((nj>>(d+(a[i]-i)))&1)) dp[i+1][nj|(1<<(d+(a[i]-i)))] = (dp[i+1][nj|(1<<(d+(a[i]-i)))] + dp[i][j]) % mod;
            }
        }
    }
    cout << dp[n][(1<<(d+1))-1] << endl;
    return 0;
}
