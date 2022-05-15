// 練習0,解説AC,解法2

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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<ll>> dp(2*n, vector<ll>(2*n, 0));
	if ((n-1)%2 == 0) rep(i, 2*n) dp[i][i] = a[i%n];
	rep3(k, 1, n) for (int i=1; i+k<2*n; ++i) {
		if ((n-(k+1))%2 == 0) dp[i][i+k] = max(dp[i+1][i+k]+a[i%n], dp[i][i+k-1]+a[(i+k)%n]);
		else dp[i][i+k] = (a[i%n]>=a[(i+k)%n]) ? dp[i+1][i+k] : dp[i][i+k-1];
	}
	ll res = 0;
	rep3(i, 1, n+1) res = max(res, dp[i][i+n-1]);
	cout << res << endl;
	return 0;
}
