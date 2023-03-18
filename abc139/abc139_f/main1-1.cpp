// 解説AC

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
		int cx = x[i], cy = y[i];
		rep(i2, 4) {
			ll xi = 0, yi = 0, lx = 0, ly = 0, rx = 0, ry = 0;
			rep(j, n) {
				ll d1 = dot(cx, cy, x[j], y[j]);
				if (d1 < 0) continue;
				if (d1 > 0) {
					xi += x[j];
					yi += y[j];
				}
				else {
					ll d2 = cross(cx, cy, x[j], y[j]);
					if (d2 > 0) {
						lx += x[j];
						ly += y[j];
					}
					else {
						rx += x[j];
						ry += y[j];
					}
				}
			}
			rep(j2, 4) {
				ll tx = xi, ty = yi;
				if (j2&1) {
					tx += lx;
					ty += ly;
				}
				if (j2&(1<<1)) {
					tx += rx;
					ty += ry;
				}
				res = max(res, sqrt(tx*tx+ty*ty));
			}
			int nx = -cy, ny = cx;
			cx = nx; cy = ny;
		}
	}
	cout << fixed << setprecision(20) << res << endl;
	return 0;
}
