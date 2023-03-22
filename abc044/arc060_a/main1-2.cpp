// 解説AC2

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
	int n, a;
	cin >> n >> a;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	int mx = max(a, *max_element(all(x))), add = mx * n, vlen = add * 2 + 1;
	vector<vector<ll>> dp(n+1, vector<ll>(vlen));
	dp[0][add] = 1;
	rep(i, n) {
		int sval = x[i] - a;
		rep(j, vlen) {
			if (j-sval>=0 && j-sval<vlen) dp[i+1][j] = dp[i][j] + dp[i][j-sval];
			else dp[i+1][j] = dp[i][j];
		}
	}
	cout << (dp[n][add]-1) << endl;
	return 0;
}
