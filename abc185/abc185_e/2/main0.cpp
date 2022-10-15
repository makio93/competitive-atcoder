// 学習2回目,自力AC

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

const int INF = (int)(1e9);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
    rep(i, n+1) rep(j, m+1) {
        if (i == 0) dp[i][j] = j;
        else if (j == 0) dp[i][j] = i;
        else {
            if (a[i-1] == b[j-1]) dp[i][j] = min({ dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1 });
            else dp[i][j] = min({ dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1 });
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
