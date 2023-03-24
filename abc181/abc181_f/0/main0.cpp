// 自力AC,ヒント有

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
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	double lval = 0.0, rval = 200.0;
	while (rval-lval >= 1e-5) {
		double cval = lval + (rval-lval) / 2.0;
		dsu d(n+2);
		rep(i, n) rep3(j, i+1, n) if ((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])) < cval*cval) d.merge(i, j);
		rep(i, n) if ((double)abs(y[i]-100) < cval) d.merge(i, n);
		rep(i, n) if ((double)abs(y[i]+100) < cval) d.merge(i, n+1);
		if (d.same(n, n+1)) rval = cval;
		else lval = cval;
	}
	double res = lval / 2.0;
	printf("%.10f\n", res);
	return 0;
}
