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

// 自力AC

const int INF = (int)(1e9);

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	ll ng = 0, ok = ng;
	rep(i, n) rep(j, i) ok = max(ok, (ll)(x[i]-x[j])*(x[i]-x[j])+(ll)(y[i]-y[j])*(y[i]-y[j]));
	while (ok-ng > 1) {
		ll cent = (ng + ok + 1) / 2;
		vector<int> g(n);
		rep(i, n) {
			g[i] = (1<<i);
			rep(j, i) if ((ll)(x[i]-x[j])*(x[i]-x[j])+(ll)(y[i]-y[j])*(y[i]-y[j]) <= cent) {
				g[i] |= (1<<j);
				g[j] |= (1<<i);
			}
		}
		vector<int> dp((1<<n), INF);
		dp[0] = 1;
		rep(i, n) {
			dp[(1<<i)] = 1;
			rep3r(j, 1, (1<<i)) if (dp[j] == 1) {
				if ((g[i]&j) == j) dp[j|(1<<i)] = min(dp[j|(1<<i)], 1);
			}
		}
		rep(i, (1<<n)) if (dp[i] >= INF) {
			rep3r(j, 1, i) {
				j &= i;
				dp[i] = min(dp[i], dp[j]+dp[i^j]);
			}
		}
		if (dp[(1<<n)-1] <= k) ok = min(ok, cent);
		else ng = max(ng, cent);
	}
	cout << ok << endl;
	return 0;
}
