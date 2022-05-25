// バチャ本番WA1

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
	if (n > m) {
		swap(n, m);
		swap(a, b);
	}
	vector<vector<int>> dp(n+1, vector<int>(m+1, INF));
	rep(i, m+1) dp[0][i] = 0;
	rep(i, n) rep(j, m) {
		if (dp[i][j] != INF) {
			if (a[i] == b[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
			else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
			dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+2);
		}
		if (dp[i+1][j] != INF) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]);
	}
	int res = (m-n) + dp[n][m];
	cout << res << endl;
	return 0;
}
