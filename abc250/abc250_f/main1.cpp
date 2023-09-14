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

const ll LINF = (ll)(5e18);

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	auto cross = [](int x1, int y1, int x2, int y2, int x3, int y3) -> ll {
		int vx1 = x2 - x1, vy1 = y2 - y1, vx2 = x3 - x1, vy2 = y3 - y1;
		return abs((ll)vx1 * vy2 - (ll)vx2 * vy1);
	};
	ll sum = 0;
	rep3(i, 1, n-1) sum += cross(x[0], y[0], x[i], y[i], x[i+1], y[i+1]);
	ll val = 0, res = LINF;
	int ri = 1;
	rep(i, n) {
		while (val*4 < sum) {
			val += cross(x[i], y[i], x[ri], y[ri], x[(ri+1)%n], y[(ri+1)%n]);
			res = min(res, abs(sum-val*4));
			ri = (ri + 1) % n;
		}
		val -= cross(x[i], y[i], x[(i+1)%n], y[(i+1)%n], x[ri], y[ri]);
		res = min(res, abs(sum-val*4));
	}
	cout << res << endl;
	return 0;
}
