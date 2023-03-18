// バチャ,自力WA

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
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	auto dist = [](int yi, int xi) -> long double {
		return sqrt((long double)yi*yi+(long double)xi*xi);
	};
	auto calc = [&](vector<int> vx, vector<int> vy) -> long double {
		vector<pair<int, int>> yx1, yx2;
		rep(i, n) {
			if (vy[i]>=0 && vx[i]>=0) yx1.emplace_back(vy[i], vx[i]);
			else yx2.emplace_back(vy[i], vx[i]);
		}
		int m = yx2.size(), yi = 0, xi = 0;
		for (const auto& pi : yx1) {
			yi += pi.first;
			xi += pi.second;
		}
		long double nval = dist(yi, xi);
		vector<bool> used(m);
		rep(i, m) {
			pair<long double, int> mval = { 0.0, -1 };
			rep(j, m) if (!used[j]) mval = max(mval, { dist(yi+yx2[j].first,xi+yx2[j].second)-nval, j });
			if (mval.second == -1) break;
			used[mval.second] = true;
			yi += yx2[mval.second].first;
			xi += yx2[mval.second].second;
			nval = dist(yi, xi);
		}
		return nval;
	};
	long double res = max(calc(x, y), calc(y, x));
	rep(i, n) x[i] *= -1;
	res = max({ res, calc(x, y), calc(y, x) });
	rep(i, n) y[i] *= -1;
	res = max({ res, calc(x, y), calc(y, x) });
	rep(i, n) x[i] *= -1;
	res = max({ res, calc(x, y), calc(y, x) });
	printf("%.30Lf\n", res);
	return 0;
}
