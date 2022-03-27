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

const int INF = (int)(1e9);

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> ab(n, vector<int>(2));
	rep(i, n) cin >> ab[i][0];
	rep(i, n) cin >> ab[i][1];
	vector<vector<bool>> dp(n, vector<bool>(2));
	dp[0] = vector<bool>(2, true);
	rep3(i, 1, n) rep(j, 2) {
		rep(j2, 2) if (dp[i-1][j2]) dp[i][j] = dp[i][j] || (abs(ab[i][j]-ab[i-1][j2]) <= k);
	}
	if (dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
