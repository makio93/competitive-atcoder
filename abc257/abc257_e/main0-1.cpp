// 本番,未提出,誤答

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
	vector<int> c(9);
	rep(i, 9) cin >> c[i];
	vector<__int128_t> dp(n+1, -1);
	dp[0] = 0;
	repr(i, 9) for (int j=0; j+c[i]<=n; ++j) if (dp[j] != (__int128_t)(-1)) {
		dp[j+c[i]] = max(dp[j+c[i]], dp[j]*10+(i+1));
	}
	__int128_t mval = 0;
	rep(i, n+1) mval = max(mval, dp[i]);
	return 0;
}
