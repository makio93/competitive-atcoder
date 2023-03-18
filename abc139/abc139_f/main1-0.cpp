// 解説,自力実装,AC

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
	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return atan2(y[li], x[li]) < atan2(y[ri], x[ri]);
	});
	ord.insert(ord.end(), all(ord));
	vector<double> rads(n*2);
	rep(i, n*2) {
		rads[i] = atan2(y[ord[i]], x[ord[i]]);
		if (i >= n) rads[i] += PI * 2;
	}
	int li = 0;
	double res = 0.0;
	auto sdist = [](ll xi, ll yi) -> ll {
		return xi * xi + yi * yi;
	};
	rep(i, n*2) {
		while (rads[li] < rads[i]-PI) ++li;
		ll xi = 0, yi = 0, pdist = sdist(xi, yi);
		rep3r(j, li, i+1) {
			if (sdist(xi+x[ord[j]], yi+y[ord[j]]) < pdist) break;
			xi += x[ord[j]];
			yi += y[ord[j]];
			pdist = sdist(xi, yi);
		}
		res = max(res, sqrt(sdist(xi, yi)));
	}
	printf("%.14f\n", res);
	return 0;
}
