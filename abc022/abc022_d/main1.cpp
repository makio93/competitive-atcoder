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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> ax(n), ay(n), bx(n), by(n);
	rep(i, n) cin >> ax[i] >> ay[i];
	rep(i, n) cin >> bx[i] >> by[i];
	auto dist = [&](vector<int>& vx, vector<int>& vy) -> double {
		double gx = 0.0, gy = 0.0;
		rep(i, n) gx += vx[i];
		rep(i, n) gy += vy[i];
		gx /= n; gy /= n;
		double mval = 0.0;
		rep(i, n) mval = max(mval, sqrt((vx[i]-gx)*(vx[i]-gx)+(vy[i]-gy)*(vy[i]-gy)));
		return mval;
	};
	double da = dist(ax, ay), db = dist(bx, by);
	printf("%.10f\n", db/da);
	return 0;
}
