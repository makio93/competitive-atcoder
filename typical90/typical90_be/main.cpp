#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答、解けない

const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m+1)), b(n, vector<int>(m+1));
	rep(i, n) {
		int ti;
		cin >> ti;
		rep(j, ti) {
			int ai;
			cin >> ai;
			a[i][ai] = 1;
		}
		rep(j, m) b[i][j+1] = (a[i][j]<<1) + a[i][j+1];
	}
	vector<int> s(m+1);
	rep(i, m) cin >> s[i+1];
	vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(m+1, vector<ll>(4)));
	rep(i, m) dp[0][i+1][0] = 1;
	dp[0][0][0] = dp[0][0][1] = 1;
	rep(i, n) rep(j, m+1) {
		rep(j2, 4) dp[i+1][j][j2] = dp[i][j][j2];
		if (j > 0) rep(j2, 4) dp[i+1][j][j2^b[i][j]] = (dp[i+1][j][j2^b[i][j]] + dp[i][j][j2]) % mod;
	}
	ll res = 1;
	rep3(i, 1, m+1) {
		int sb = (s[i-1] << 1) + s[i];
		res = (res * dp[n][i][sb]) % mod;
	}
	cout << res << endl;
	return 0;
}
