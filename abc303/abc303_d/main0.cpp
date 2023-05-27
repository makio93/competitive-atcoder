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
	int x, y, z;
	string s;
	cin >> x >> y >> z >> s;
	int n = s.length();
	vector<vector<ll>> dp(n+1, vector<ll>(2, LINF));
	dp[0][0] = 0;
	rep(i, n) {
		dp[i][1] = min(dp[i][1], dp[i][0]+z);
		dp[i][0] = min(dp[i][0], dp[i][1]+z);
		if (s[i] == 'a') {
			dp[i+1][0] = dp[i][0] + x;
			dp[i+1][1] = dp[i][1] + y;
		}
		if (s[i] == 'A') {
			dp[i+1][0] = dp[i][0] + y;
			dp[i+1][1] = dp[i][1] + x;
		}
	}
	ll res = min(dp[n][0], dp[n][1]);
	cout << res << endl;
	return 0;
}
