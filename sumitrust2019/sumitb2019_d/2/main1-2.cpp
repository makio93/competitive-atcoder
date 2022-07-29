// 復習2回目,解説AC2

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
    string s;
    cin >> n >> s;
    vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(4, vector<bool>(1000)));
    dp[0][0][0] = true;
    rep(i, n) {
        int val = s[i] - '0';
        rep(j, 4) rep(k, 1000) if (dp[i][j][k]) {
            if (j+1 < 4) dp[i+1][j+1][k*10+val] = true;
            dp[i+1][j][k] = true;
        }
    }
    int res = 0;
    rep(i, 1000) if (dp[n][3][i]) ++res;
    cout << res << endl;
    return 0;
}
