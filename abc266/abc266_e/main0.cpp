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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<double> dp(n);
	rep3(i, 1, 7) dp[n-1] += i;
	dp[n-1] /= 6.0;
	repr(i, n-1) {
		rep3(j, 1, 7) dp[i] += max((double)j, dp[i+1]);
		dp[i] /= 6.0;
	}
	printf("%.10f\n", dp[0]);
	return 0;
}
