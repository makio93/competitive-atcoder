// 解説AC1

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
	int mx = max(a, *max_element(all(x))), vlen = mx * n + 1;
	vector dp(n+1, vector(n+1, vector(vlen+1, 0LL)));
	dp[0][0][0] = 1;
	rep3(i, 1, n+1) rep(j, i+1) rep(k, vlen+1) {
		dp[i][j][k] += dp[i-1][j][k];
		if (j-1>=0 && k-x[i-1]>=0) dp[i][j][k] += dp[i-1][j-1][k-x[i-1]]; 
	}
	ll res = 0;
	rep3(i, 1, n+1) res += dp[n][i][a*i];
	cout << res << endl;
	return 0;
}
