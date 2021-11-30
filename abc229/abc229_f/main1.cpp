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

// 解説AC

const ll INF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2, INF)));
	dp[0][0][0] = a[0];
	dp[0][1][1] = 0;
	rep3(i, 1, n) rep(j, 2) rep(k, 2) rep(j2, 2) {
		dp[i][j][k] = min(dp[i][j][k], dp[i-1][j2][k]+(j==0?(ll)a[i]:0)+(j==j2?(ll)b[i-1]:0));
	}
	rep(k, 2) rep(j2, 2) dp[n][k][k] = min(dp[n][k][k], dp[n-1][j2][k]+(k==j2?(ll)b[n-1]:0));
	ll ans = INF;
	rep(j, 2) rep(k, 2) ans = min(ans, dp[n][j][k]);
	cout << ans << endl;
	return 0;
}
