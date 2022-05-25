// 解説AC

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
    rep(i, n+1) dp[i][0] = i;
    rep(i, m+1) dp[0][i] = i;
    rep(i, n) rep(j, m) {
        dp[i+1][j+1] = min(dp[i][j+1]+1, dp[i+1][j]+1);
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+(a[i]==b[j]?0:1));
    }
    cout << dp[n][m] << endl;
    return 0;
}