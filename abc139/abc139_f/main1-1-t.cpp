// 解説,研究,WAになる

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
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	double res = 0.0;
	auto dot = [](int x1, int y1, int x2, int y2) -> ll {
		return (ll)x1 * x2 + (ll)y1 * y2;
	};
	auto cross = [](int x1, int y1, int x2, int y2) -> ll {
		return (ll)x1 * y2 - (ll)x2 * y1;
	};
	rep(i, n) {
		int cx = y[i], cy = -x[i], mi = 1;
		rep(i2, 2) {
			ll xi = 0, yi = 0;
			rep(j, n) {
				ll d1 = dot(cx, cy, x[j], y[j]);
				if (d1 < 0) continue;
				if (d1 > 0) {
					xi += x[j];
					yi += y[j];
				}
				else {
					if (cross(cx, cy, x[j], y[j])*mi > 0) {
						xi += x[j];
						yi += y[j];
					}
				}
			}
			res = max(res, sqrt((ll)xi*xi+(ll)yi*yi));
			cx = -cx; cy = -cy; mi = -mi;
		}
	}
	cout << fixed << setprecision(20) << res << endl;
	return 0;
}
