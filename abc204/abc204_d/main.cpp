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
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	int sum = 0, m = 0;
	rep(i, n) sum += t[i];
	m = (sum + 1) / 2;
	vector<vector<bool>> dp(n+1, vector<bool>(m+1));
	dp[0][0] = true;
	rep(i, n) rep(j, m+1) if (dp[i][j]) {
		dp[i+1][j] = dp[i+1][j] | dp[i][j];
		if (j+t[i] <= m) dp[i+1][j+t[i]] = dp[i+1][j+t[i]] | dp[i][j];
	}
	int res = (int)(1e9);
	repr(i, m+1) if (dp[n][i]) {
		res = min(res, max(i, sum - i));
		break;
	}
	cout << res << endl;
	return 0;
}
