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

const double PI = acos((double)(-1));
const int INF = (int)(1e9);

int main() {
	int a, b, d;
	cin >> a >> b >> d;
	d %= 360;
	double rd = d * PI / 180.0;
	double ta = a * cos(rd) - b * sin(rd), tb = a * sin(rd) + b * cos(rd);
	printf("%.14f %.14f\n", ta, tb);
	return 0;
}
