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
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<ll>> dp(n+1, vector<ll>(3001));
	dp[0] = vector<ll>(3001, 1);
	rep(i, n) {
		rep3(j, a[i], b[i]+1) dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
		rep(j, 3000) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i+1][j]) % mod;
	}
	cout << dp[n][3000] << endl;
	return 0;
}
