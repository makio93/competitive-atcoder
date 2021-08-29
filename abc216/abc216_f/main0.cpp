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

// 本番AC

const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<pair<int, int>> ab(n);
	rep(i, n) ab[i] = { a[i], b[i] };
	sort(all(ab));
	ll res = 0;
	vector<vector<ll>> dp(n+1, vector<ll>(5001));
	dp[0][0] = 1;
	rep3(i, 1, n+1) {
		rep(j, 5001) if (j-ab[i-1].second >= 0) {
			dp[i][j] = (dp[i][j] + dp[i-1][j-ab[i-1].second]) % mod;
			if (j <= ab[i-1].first) res = (res + dp[i-1][j-ab[i-1].second]) % mod;
		}
		rep(j, 5001) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
	}
	cout << res << endl;
	return 0;
}
