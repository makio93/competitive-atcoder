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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> dp(n, LINF), dp2(n, LINF);
	dp[0] = a[0];
	dp[1] = a[0];
	dp2[0] = a[n-1];
	rep3(i, 1, n-1) dp[i+1] = min({ dp[i+1], dp[i]+a[i], dp[i-1]+a[i] });
	rep(i, n-1) {
		if (i+1 == n-1) dp2[i+1] = min({ dp2[i+1], dp2[i], dp2[i-1]+a[i] });
		else if (i-1 >= 0) dp2[i+1] = min({ dp2[i+1], dp2[i]+a[i], dp2[i-1]+a[i] });
		else dp2[i+1] = min(dp2[i+1], dp2[i]+a[i]);
	}
	ll res = min(dp[n-1], dp2[n-1]);
	cout << res << endl;
	return 0;
}
