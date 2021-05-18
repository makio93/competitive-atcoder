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

// 自力で解答、AC

using mint = modint1000000007;

int main() {
	int k;
	cin >> k;
	vector<vector<mint>> dp(k+1, vector<mint>(9));
	dp[0][0] = 1;
	rep(i, k) rep(j, 9) {
		rep3(j2, 1, 10) if (i+j2 <= k) {
			int nj = (j * 10 + j2) % 9;
			dp[i+j2][nj] += dp[i][j];
		}
	}
	cout << dp[k][0].val() << endl;
	return 0;
}
