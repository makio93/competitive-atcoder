// 解説AC1-0

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

const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	vector<vector<ll>> dp(n+1, vector<ll>(n+1));
	dp[0][0] = 1;
	rep(i, n) {
		int li = i, ri = i;
		while (li>=0 && p[li]<=p[i]) --li;
		++li;
		while (ri<n && p[ri]<=p[i]) ++ri;
		rep(j, n+1) {
			if (j>=li && j<ri) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i+1][j] + dp[i][j]) % mod;
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}
