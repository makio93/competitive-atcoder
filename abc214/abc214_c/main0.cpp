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

const ll INF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> s(n), t(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	vector<ll> dp(2*n+1, INF);
	rep(i, 2*n) {
		if (i >= n) {
			dp[i] = min(dp[i], dp[i-n]);
			dp[i+1] = min(dp[i+1], dp[i-n+1]);
		}
		dp[i] = min(dp[i], (ll)t[i%n]);
		dp[i+1] = min(dp[i+1], dp[i]+s[i%n]);
	}
	vector<ll> res(n);
	rep(i, n) res[i] = min(dp[i], dp[i+n]);
	rep(i, n) cout << res[i] << endl;
	return 0;
}
