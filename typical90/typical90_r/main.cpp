#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const double PI = acos(-1);

int main() {
	int t, l, x, y, q;
	cin >> t >> l >> x >> y >> q;
	vector<int> e(q);
	rep(i, q) cin >> e[i];
	rep(i, q) {
		double yi = fabs((double)y + (l/2.0) * sin(e[i]*2.0/t*PI));
		double hi = (l/2.0) - (l/2.0) * cos(e[i]*2.0/t*PI);
		double di = sqrt((double)x*x + yi*yi);
		double ri = fabs(atan(hi/di) / PI * 180.0);
		printf("%.10f\n", ri);
	}
	return 0;
}
