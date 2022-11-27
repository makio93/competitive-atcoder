// 

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
	ll a, b;
	cin >> a >> b;
	ll li = 0, ri = a / b;
	auto calc = [&](ll val) -> double {
		ll sval = val * b, gval = val + 1;
		return sval + a / sqrt(gval);
	};
	double lval = calc(li), rval = calc(ri);
	while (ri-li > 0) {
		ll cl = li + (ri-li+1) / 3, cr = ri - (ri-li+1) / 3;
		double clval = calc(cl), crval = calc(cr);
		if (min(clval, crval) < min(lval, rval)) {
			if (clval <= crval) {
				ri = cr;
				rval = crval;
			}
			else {
				li = cl;
				lval = clval;
			}
		}
		else {
			if (lval <= rval) {
				ri = cl;
				rval = clval;
			}
			else {
				li = cr;
				lval = crval;
			}
		}
	}
	double res = lval;
	printf("%.10f\n", res);
	return 0;
}
