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

// 解説を読んで解答を作成、個人的な練習

int main() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> tup(n);
	rep(i, n) cin >> get<0>(tup[i]) >> get<1>(tup[i]) >> get<2>(tup[i]);
	sort(all(tup));
	vector<int> d(n), c(n), s(n);
	rep(i, n) {
		d[i] = get<0>(tup[i]);
		c[i] = get<1>(tup[i]);
		s[i] = get<2>(tup[i]);
	}
	int dmx = d.back();
	vector<vector<ll>> dp(n+1, vector<ll>(dmx+1));
	rep(i, n) rep(j, dmx+1) {
		dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
		if (j<=d[i] && c[i]<=j) dp[i+1][j] = max(dp[i+1][j], dp[i][j-c[i]]+s[i]);
	}
	ll res = 0;
	rep(i, dmx+1) res = max(res, dp[n][i]);
	cout << res << endl;
	return 0;
}
