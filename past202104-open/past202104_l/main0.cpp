// 自力AC

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

const double DINF = 1e18;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n+m), y(n+m), r(n+m);
	rep(i, n) cin >> x[i] >> y[i];
	rep(i, m) cin >> x[n+i] >> y[n+i] >> r[n+i];
	vector<pair<double, pair<int, int>>> elst;
	rep(i, n+m) rep3(j, i+1, n+m) {
		int d2 = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
		double d1 = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
		if (d2>=abs(r[i]-r[j])*abs(r[i]-r[j]) && d2<=(r[i]+r[j])*(r[i]+r[j])) elst.emplace_back(0.0, make_pair(i, j));
		else if (d2 < abs(r[i]-r[j])*abs(r[i]-r[j])) elst.emplace_back(abs(r[i]-r[j])-d1, make_pair(i, j));
		else elst.emplace_back(d1-(r[i]+r[j]), make_pair(i, j));
	}
	sort(all(elst));
	double res = DINF;
	int elen = elst.size();
	rep(i, 1<<m) {
		double val = 0.0;
		dsu uf(n+m);
		rep(j, elen) {
			auto [di, pi] = elst[j];
			auto [li, ri] = pi;
			if (li >= n && !(i&(1<<(li-n)))) continue;
			if (ri >= n && !(i&(1<<(ri-n)))) continue;
			if (uf.same(li, ri)) continue;
			uf.merge(li, ri);
			val += di;
		}
		res = min(res, val);
	}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}
