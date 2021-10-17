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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	int sum = 0;
	rep(i, n) sum += a[i];
	double lval = 0.0, rval = (double)(sum);
	while ((rval-lval) > (double)(1e-7)) {
		double cval = lval + (rval - lval) / 2.0;
		double lt = 0.0, rt = 0.0;
		int lp = 0, rp = sum;
		rep(i, n) {
			if ((double)(lp+a[i]) <= cval) {
				lt += (double)a[i] / b[i];
				lp += a[i];
			}
			else {
				lt += (double)(cval-lp) / b[i];
				break;
			}
		}
		repr(i, n) {
			if ((double)(rp-a[i]) >= cval) {
				rt += (double)a[i] / b[i];
				rp -= a[i];
			}
			else {
				rt += (double)(rp-cval) / b[i];
				break;
			}
		}
		if (lt < rt) lval = cval;
		else rval = cval;
	}
	double res = (lval + rval) / 2.0;
	printf("%.14f\n", res);
	return 0;
}
