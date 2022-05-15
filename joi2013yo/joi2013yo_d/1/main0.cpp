// 学習1回目,自力AC

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
	vector<vector<int>> dp(d, vector<int>(n, -INF));
	rep(i, n) if (t[0]>=a[i] && t[0]<=b[i]) dp[0][i] = 0;
	rep(i, d-1) rep(j, n) if (dp[i][j] != -INF) rep(j2, n) if (t[i+1]>=a[j2] && t[i+1]<=b[j2]) {
		dp[i+1][j2] = max(dp[i+1][j2], dp[i][j]+abs(c[j]-c[j2]));
	}
	int res = 0;
	rep(i, n) res = max(res, dp[d-1][i]);
	cout << res << endl;
	return 0;
}
