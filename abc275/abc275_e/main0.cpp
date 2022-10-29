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

using mint = modint998244353;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<mint>> dp(k+1, vector<mint>(n));
	rep3(i, 1, k+1) repr(j, n) {
		int li = j + 1, ri = j + m + 1;
		for (int ti=li; ti<min(ri,n); ++ti) dp[i][j] += dp[i-1][ti] / m;
		if (n>=li && n<ri) dp[i][j] += mint(1) / m;
		if (ri > n+1) {
			int li2 = n - (j + m - n), ri2 = n;
			for (int ti=li2; ti<ri2; ++ti) dp[i][j] += dp[i-1][ti] / m;
		}
	}
	cout << dp[k][0].val() << endl;
	return 0;
}
