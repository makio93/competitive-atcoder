// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int mod = 100000;

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m+1, vector<int>(s+1)));
    dp[0][0][0] = 1;
    rep(i, n*n+1) {
        int to = (i+1)%2, fr = i%2;
        if (i>0) rep(j, m) rep(k, s) {
            dp[fr][j+1][k+1] = (dp[fr][j+1][k+1] + dp[fr][j][k]) % mod;
        }
        if (i==n*n) break;
        rep(j, m) rep(k, s) {
            if (k+j+1<=s) dp[to][j+1][k+j+1] = (dp[to][j+1][k+j+1] + dp[fr][j][k]) % mod;
        }
        dp[fr] = vector<vector<int>>(m+1, vector<int>(s+1));
    }
    int ans = 0;
    rep(i, m+1) ans = (ans + dp[n*n%2][i][s]) % mod;
    rep(i, m+1) ans = (ans - dp[(n*n-1)%2][i][s] + mod) % mod;
    cout << ans << endl;
    return 0;
}
