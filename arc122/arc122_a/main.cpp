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

const ll mod = (ll)(1e9) + 7;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<ll>> cnt(n+1, vector<ll>(2));
	vector<vector<ll>> dp(n+1, vector<ll>(2));
	cnt[n][0] = 1;
	cnt[n][1] = 0;
	repr(i, n) {
		cnt[i][0] = (cnt[i][0] + cnt[i+1][0] + cnt[i+1][1]) % mod;
		cnt[i][1] = (cnt[i][1] + cnt[i+1][0]) % mod;
		dp[i][0] = (dp[i][0] + dp[i+1][0] + dp[i+1][1] + (cnt[i][0] * a[i] % mod)) % mod;
		dp[i][1] = (dp[i][1] + dp[i+1][0] + (cnt[i][1] * (-a[i]) % mod) + mod) % mod;
	}
	cout << dp[0][0] << endl;
	return 0;
}
