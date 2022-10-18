// 学習1回目,バチャ本番AC

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
const double PI = acos(-1);

int main() {
	int n, x0, y0, x2, y2;
	cin >> n >> x0 >> y0 >> x2 >> y2;
	double rx = (x0 + x2) / 2.0, ry = (y0 + y2) / 2.0;
	double rad = PI * 2.0 / n;
	double tx = (x0 - rx) * cos(rad) - (y0 - ry) * sin(rad) + rx, ty = (x0 - rx) * sin(rad) + (y0 - ry) * cos(rad) + ry;
	cout << fixed << setprecision(10) << tx << ' ' << ty << endl;
	return 0;
}
