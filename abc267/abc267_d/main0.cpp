// 本番AC

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

const ll LINF = (ll)(1e18);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<ll>> dp(n+1, vector<ll>(m+1, -LINF));
	dp[0][0] = 0;
	rep(i, n) rep(j, m+1) {
		if (dp[i][j] != -LINF) dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		if (j-1>=0 && dp[i][j-1]!=-LINF) dp[i+1][j] = max(dp[i+1][j], dp[i][j-1]+(ll)j*a[i]); 
	}
	cout << dp[n][m] << endl;
	return 0;
}
