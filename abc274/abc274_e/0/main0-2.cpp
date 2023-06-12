// 自力AC2

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

const double INF = 1e18;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n), p(m), q(m);
	rep(i, n) cin >> x[i] >> y[i];
	rep(i, m) cin >> p[i] >> q[i];
	vector<vector<double>> dp(1<<(n+m+1), vector<double>(n+m+1, INF));
	auto dist = [&](int id1, int id2) -> double {
		int x1 = (id1 < n) ? x[id1] : (id1 < n+m) ? p[id1-n] : 0, y1 = (id1 < n) ? y[id1] : (id1 < n+m) ? q[id1-n] : 0;
		int x2 = (id2 < n) ? x[id2] : (id2 < n+m) ? p[id2-n] : 0, y2 = (id2 < n) ? y[id2] : (id2 < n+m) ? q[id2-n] : 0;
		return sqrt((ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2));
	};
	rep(i, 1<<m) dp[(1<<(m+n))+((1<<n)-1)+(i<<n)][n+m] = 0.0;
	repr(i, (1<<(n+m+1))-1) {
		int mul = 1 << __builtin_popcount((i>>n)&((1<<m)-1));
		rep(j, n+m+1) if (i&(1<<j)) {
			rep(j2, n+m+1) if (!(i&(1<<j2))) dp[i][j] = min(dp[i][j], dp[i|(1<<j2)][j2]+dist(j,j2)/mul);
		}
	}
	double res = INF;
	rep(i, n+m+1) res = min(res, dp[1<<i][i]+dist(n+m,i));
	printf("%.10f\n", res);
	return 0;
}
