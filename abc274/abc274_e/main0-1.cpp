// 自力AC1

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
	vector<vector<double>> memo(1<<(n+m+1), vector<double>(n+m+1, INF));
	vector<vector<bool>> finished(1<<(n+m+1), vector<bool>(n+m+1));
	auto dist = [&](int id1, int id2) -> double {
		int x1 = (id1 < n) ? x[id1] : (id1 < n+m) ? p[id1-n] : 0, y1 = (id1 < n) ? y[id1] : (id1 < n+m) ? q[id1-n] : 0;
		int x2 = (id2 < n) ? x[id2] : (id2 < n+m) ? p[id2-n] : 0, y2 = (id2 < n) ? y[id2] : (id2 < n+m) ? q[id2-n] : 0;
		return sqrt((ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2));
	};
	auto calc = [&](auto calc, int si, int vi) -> double {
		if (finished[si][vi]) return memo[si][vi];
		if (vi==n+m && (si&((1<<n)-1))==(1<<n)-1 && (si&(1<<(n+m)))) return memo[si][vi] = 0.0;
		int mul = 1 << __builtin_popcount((si >> n) & ((1<<m) - 1));
		double rval = INF;
		rep(i, n+m+1) if (!(si&(1<<i))) rval = min(rval, calc(calc,si|(1<<i),i)+dist(vi,i)/mul);
		finished[si][vi] = true;
		return memo[si][vi] = rval;
	};
	double res = INF;
	rep(i, n+m) res = min(res, calc(calc,1<<i,i)+dist(n+m,i));
	printf("%.10f\n", res);
	return 0;
}
