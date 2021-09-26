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

// 本番AC

const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<ll>> dp(n+1, vector<ll>(10));
	dp[0][0] = 1;
	rep(i, n) dp[i+1][a[i]] = 1;
	rep3(i, 1, n) {
		vector<ll> ndp(10);
		rep(j1, 10) rep(j2, 10) {
			ndp[(j1+j2)%10] = (ndp[(j1+j2)%10] + dp[i][j1] * dp[i+1][j2] % mod) % mod;
			ndp[(j1*j2)%10] = (ndp[(j1*j2)%10] + dp[i][j1] * dp[i+1][j2] % mod) % mod;
		}
		swap(dp[i+1], ndp);
	}
	rep(i, 10) cout << dp[n][i] << endl;
	return 0;
}
