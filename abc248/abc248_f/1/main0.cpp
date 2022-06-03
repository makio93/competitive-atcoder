// バチャ参加,自力AC

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
	int n;
	ll p;
	cin >> n >> p;
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2)));
	dp[0][0][0] = dp[0][1][1] = 1;
	rep(i, n-1) rep(j, n) {
		dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0]) % p;
		if (j+1 < n) dp[i+1][j+1][0] = (dp[i+1][j+1][0] + dp[i][j][0] * 3) % p;
		if (j+2 < n) dp[i+1][j+2][1] = (dp[i+1][j+2][1] + dp[i][j][0] * 2) % p;
		dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][1]) % p;
		if (j+1 < n) dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][1]) % p;
	}
	rep3(i, 1, n) printf("%d%c", (int)(dp[n-1][i][0]), (i<n-1?' ':'\n'));
	return 0;
}
