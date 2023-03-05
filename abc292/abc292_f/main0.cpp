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

const double PI = acos(-1);

const int INF = (int)(1e9);

int main() {
	int a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	double lval = 15 / 180.0 * PI, rval = 30 / 180.0 * PI, aval = 30 / 180.0 * PI;
	while (abs(rval-lval) > 1e-9) {
		double cval = lval + (rval - lval) / 2.0, bval = aval - cval;
		double di = a / cos(cval), ti = di * cos(bval);
		if (ti <= (double)(b)) lval = cval;
		else rval = cval;
	}
	double res = a / cos(rval);
	printf("%.14f\n", res);
	return 0;
}
