// 自力AC

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
const string tar = "RBW";

int main() {
	int n;
	cin >> n;
	vector<string> s(5);
	rep(i, 5) cin >> s[i];
	vector<vector<int>> dp(n, vector<int>(3, INF));
	rep(i, 3) {
		int cnt = 0;
		rep(j, 5) if (s[j][0] != tar[i]) ++cnt;
		dp[0][i] = cnt;
	}
	rep3(i, 1, n) rep(j, 3) {
		int cnt = 0;
		rep(j2, 5) if (s[j2][i] != tar[j]) ++cnt;
		int pval = INF;
		rep(j2, 3) if (j2 != j) pval = min(pval, dp[i-1][j2]);
		dp[i][j] = cnt + pval;
	}
	int res = INF;
	rep(i, 3) res = min(res, dp[n-1][i]);
	cout << res << endl;
	return 0;
}
