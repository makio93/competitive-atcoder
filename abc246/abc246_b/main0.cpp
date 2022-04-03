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
	int a, b;
	cin >> a >> b;
	double x = 0.0, y = 0.0;
	if (a == 0) y = 1.0;
	else if (b == 0) x = 1.0;
	else {
		double r = sqrt(a*a+b*b);
		x = a / r, y = b / r;
	}
	printf("%.10f %.10f\n", x, y);
	return 0;
}
