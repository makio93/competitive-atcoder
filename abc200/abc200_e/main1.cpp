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

// 解説を見てから実装、AC

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<vector<ll>> dp(4, vector<ll>(3*n+2));
	dp[0][0] = 1;
	rep(i, 3) {
		rep3(j, i, n*(i+1)) {
			dp[i+1][j+1] += dp[i][j];
			int jmax = min(3*n+1, j+n+1);
			dp[i+1][jmax] -= dp[i][j];
		}
		rep(j, n*(i+1)+1) dp[i+1][j+1] += dp[i+1][j];
	}
	int sum = 0;
	rep3(i, 3, n*3+1) {
		if (k > dp[3][i]) k -= dp[3][i];
		else {
			sum = i;
			break;
		}
	}
	vector<int> res(3);
	rep3(i, 1, n+1) {
		int c2min = max(1, sum-i-n), c2max = min(n, sum-i-1);
		if (c2max < c2min) continue;
		int len = c2max - c2min + 1;
		if (k > len) k -= len;
		else {
			int c2 = c2min+(int)k-1;
			res = { i, c2, sum-i-c2 };
			break;
		}
	}
	rep(i, 3) printf("%d%c", res[i], (i<2?' ':'\n'));
	return 0;
}
