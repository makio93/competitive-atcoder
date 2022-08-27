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
	int n;
	cin >> n;
	vector<int> t(n), x(n), a(n);
	rep(i, n) cin >> t[i] >> x[i] >> a[i];
	vector<vector<ll>> dp(t[n-1]+1, vector<ll>(5, -LINF));
	map<pair<int, int>, ll> alst;
	rep(i, n) alst[{ t[i], x[i] }] += a[i];
	dp[0][0] = 0;
	rep(i, t[n-1]) rep(j, 5) if (dp[i][j] != -LINF) {
		if (j-1 >= 0) {
			int nj = j - 1;
			if (alst.find({ i+1, nj }) != alst.end()) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+alst[{ i+1, nj }]);
			else dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]);
		}
		if (j+1 < 5) {
			int nj = j + 1;
			if (alst.find({ i+1, nj }) != alst.end()) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]+alst[{ i+1, nj }]);
			else dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]);
		}
		if (alst.find({ i+1, j }) != alst.end()) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+alst[{ i+1, j }]);
		else dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
	}
	ll res = -LINF;
	rep(i, 5) res = max(res, dp[t[n-1]][i]);
	cout << res << endl;
	return 0;
}
