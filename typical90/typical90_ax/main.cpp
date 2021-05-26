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

// 自力AC

const ll mod = (ll)(1e9) + 7;

int main() {
	int n, l;
	cin >> n >> l;
	vector<ll> dp(n+1);
	dp[0] = 1;
	rep(i, n) {
		dp[i+1] = (dp[i+1] + dp[i]) % mod;
		if (i+l <= n) dp[i+l] = (dp[i+l] + dp[i]) % mod;
	}
	cout << dp[n] << endl;
	return 0;
}
