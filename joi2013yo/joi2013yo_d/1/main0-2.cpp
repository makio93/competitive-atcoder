// 学習1回目,自力AC2

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
	int d, n;
	cin >> d >> n;
	vector<int> t(d);
	rep(i, d) cin >> t[i];
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	vector<vector<int>> cids(d, { INF, -INF });
	rep(i, d) rep(j, n) if (t[i]>=a[j] && t[i]<=b[j]) {
		cids[i][0] = min(cids[i][0], c[j]);
		cids[i][1] = max(cids[i][1], c[j]);
	}
	vector<vector<int>> dp(d, vector<int>(2, -INF));
	rep(i, 2) dp[0][i] = 0;
	rep(i, d-1) rep(j, 2) rep(j2, 2) {
		dp[i+1][j2] = max(dp[i+1][j2], dp[i][j]+abs(cids[i][j]-cids[i+1][j2]));
	}
	int res = 0;
	rep(i, 2) res = max(res, dp[d-1][i]);
	cout << res << endl;
	return 0;
}
