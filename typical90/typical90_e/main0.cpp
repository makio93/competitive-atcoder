// 自力で実装、小課題1のみの得点

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

using mint = modint1000000007;

int main() {
	ll n;
	int b, k;
	cin >> n >> b >> k;
	vector<int> c(k);
	rep(i, k) cin >> c[i];
	vector<vector<mint>> dp(2, vector<mint>(b));
	dp[0][0] = 1;
	for (ll i=0; i<n; ++i) {
		dp[1] = vector<mint>(b);
		rep(j, b) {
			int mval = j;
			rep(j2, k) {
				int mval2 = (mval * 10 + c[j2]) % b;
				dp[1][mval2] += dp[0][j];
			}
		}
		swap(dp[0], dp[1]);
	}
	cout << dp[0][0].val() << endl;
	return 0;
}
