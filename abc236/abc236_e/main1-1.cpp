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

// 解説AC1

const int INF = (int)(1e9);
const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll l1 = 1LL, r1 = (ll)(1e12) + 1;
	while (r1-l1 > 1LL) {
		ll c = l1 + (r1-l1) / 2LL;
		vector<ll> b(n);
		rep(i, n) b[i] = a[i] * (ll)(1e3) - c;
		vector<vector<ll>> dp(n+1, vector<ll>(2, -LINF));
		dp[0][0] = dp[0][1] = 0LL;
		rep(i, n) {
			dp[i+1][1] = max(dp[i][0]+b[i], dp[i][1]+b[i]);
			dp[i+1][0] = dp[i][1];
		}
		bool ok = false;
		rep(i, 2) if (dp[n][i] >= 0LL) ok = true;
		if (ok) l1 = c;
		else r1 = c;
	}
	printf("%.10f\n", l1/(double)(1e3));
	int l2 = 0, r2 = (int)(1e9) + 1;
	while (r2-l2 > 1) {
		int c = l2 + (r2-l2) / 2;
		vector<int> b(n);
		rep(i, n) b[i] = (a[i] >= c) ? 1 : -1;
		vector<vector<int>> dp(n+1, vector<int>(2, -INF));
		dp[0][0] = dp[0][1] = 0;
		rep(i, n) {
			dp[i+1][1] = max(dp[i][0]+b[i], dp[i][1]+b[i]);
			dp[i+1][0] = dp[i][1];
		}
		bool ok = false;
		rep(i, 2) if (dp[n][i] > 0) ok = true;
		if (ok) l2 = c;
		else r2 = c;
	}
	cout << l2 << endl;
	return 0;
}
