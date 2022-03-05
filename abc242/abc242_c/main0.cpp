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

const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> dp(n, vector<ll>(9));
	dp[0] = vector<ll>(9, 1);
	rep3(i, 1, n) rep(j, 9) {
		rep3(i2, -1, 2) if (j+1+i2>=1 && j+1+i2<=9) dp[i][j] = (dp[i][j] + dp[i-1][j+i2]) % mod;
	}
	ll res = 0;
	rep(i, 9) res = (res + dp[n-1][i]) % mod;
	cout << res << endl;
	return 0;
}
