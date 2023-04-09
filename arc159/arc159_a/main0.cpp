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
	int n, k, q;
	cin >> n >> k;
	vector a(n, vector(n, 0));
	rep(i, n) rep(j, n) cin >> a[i][j];
	vector dp(n, vector(n, INF));
	rep(i, n) rep(j, n) if (a[i][j] == 1) dp[i][j] = 1;
	rep(t, n) rep(i, n) rep(j, n) dp[i][j] = min(dp[i][j], dp[i][t]+dp[t][j]);
	cin >> q;
	rep(i, q) {
		ll si, ti;
		cin >> si >> ti;
		--si; --ti;
		ll val = dp[si%n][ti%n];
		if (val >= (ll)INF) cout << -1 << endl;
		else cout << val << endl;
	}
	return 0;
}
