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
    rep3(i, 1, n*n+1) {
        int fr = (i-1)%2, to = i%2;
        vector<vector<int>> tmp(m+1, vector<int>(s+1));
        rep3(j, 1, m+1) rep3(k, 1, s+1) if (k-(n*n-i+1)>=0) {
            tmp[j][k] = (tmp[j][k] + dp[fr][j-1][k-(n*n-i+1)]) % mod;
            tmp[j][k] = (tmp[j][k] + tmp[j-1][k-(n*n-i+1)]) % mod;
        }
        dp[to] = tmp;
    }
    int ans = 0;
    rep(j, m+1) ans = (ans + dp[(n*n)%2][j][s]) % mod;
    cout << ans << endl;
    return 0;
}
