// 自力AC

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

const int INF = (int)(1.5e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> d(n), c(m);
	rep(i, n) cin >> d[i];
	rep(i, m) cin >> c[i];
	vector<int> dp(n+1, INF);
	dp[0] = 0;
	rep(i, m) repr(j, n) if (dp[j] != INF) dp[j+1] = min(dp[j+1], dp[j]+d[j]*c[i]);
	cout << dp[n] << endl;
	return 0;
}
