// 学習1回目,バチャ解説AC1

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
	int n, m;
	cin >> n >> m;
	vector<int> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai] |= 1 << bi;
		g[bi] |= 1 << ai;
	}
	rep(i, n) g[i] |= 1 << i;
	vector<int> dp(1<<n, INF);
	dp[0] = 1;
	rep(i, n) rep(j, 1<<n) if (dp[j] == 1 && (g[i] & j) == j) dp[j|1<<i] = 1;
	rep(i, 1<<n) for (int j=i; j>0; j=(j-1)&i) dp[i] = min(dp[i], dp[j]+dp[i^j]);
	cout << dp[(1<<n)-1] << endl;
	return 0;
}
