// バチャ本番WA3

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
	vector<vector<int>> dp(n+1, vector<int>(m+1));
	rep(i, n) rep(j, m) {
		dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		if (a[i] == b[j]) dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+1);
	}
	int res = n + m - dp[n][m];
	cout << (res/2) << endl;
	return 0;
}
