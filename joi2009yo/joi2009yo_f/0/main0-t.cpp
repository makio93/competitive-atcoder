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
    vector<vector<vector<int>>> dp(3, vector<vector<int>>(m+2, vector<int>(s+m+2)));
    dp[0][1][1] = 1;
    rep(i, n*n+1) {
        int fr = i % 2, to = (i+1) % 2;
        rep3(j, 1, m+1) rep3(k, 1, s+m+1) {
            dp[fr][j+1][k+1] = (dp[fr][j+1][k+1] + dp[fr][j][k]) % mod;
        }
        if (i == n*n) break;
        rep3(j, 1, m+1) rep3(k, 1, s+m+1) {
            if (k+j+1<=s+m+1) dp[to][j+1][k+j+1] = (dp[to][j+1][k+j+1] + dp[fr][j][k]) % mod;
        }
        
        dp[fr] = vector<vector<int>>(m+2, vector<int>(s+m+2));
    }
    //if (m < 10) rep(i, 2) rep(j, m+2) rep(k, s+m+2) printf("%lld%c", dp[i][j][k], (k<s+m+1?' ':'\n'));
    cout << dp[n*n%2][m+1][s+m+1] << endl;
    return 0;
}
