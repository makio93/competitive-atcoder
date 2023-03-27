// 解説AC

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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<mint> dp(2);
	dp[0] = 1;
	mint res = dp[0];
	rep3(i, 1, n+3) {
		if (i == 1) dp[i%2] = dp[(i-1)%2] * mint(2).pow(n);
		else dp[i%2] = dp[(i-1)%2] * (mint(2).pow(n) - mint(2).pow(i-2)) / i;
		res += dp[i%2];
	}
	cout << res.val() << endl;
	return 0;
}
