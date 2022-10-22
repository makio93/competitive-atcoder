// 自力WA

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

const long double INF = 1e9, EPS = 1e-6;

int main() {
	int n, a;
	cin >> n >> a;
	vector<int> w(n), x(n), v(n);
	rep(i, n) cin >> w[i] >> x[i] >> v[i];
	auto calc = [&](long double ti) -> int {
		vector<pair<long double, int>> tx(n);
		rep(i, n) tx[i] = { x[i]+v[i]*ti, w[i] };
		sort(all(tx));
		vector<int> wsum(n+1);
		rep(i, n) wsum[i+1] = wsum[i] + tx[i].second;
		int lid = 0, rval = 0;
		rep(rid, n) {
			while (lid<rid+1 && tx[rid].first-tx[lid].first>(long double)a) ++lid;
			rval = max(rval, wsum[rid+1]-wsum[lid]);
		}
		return rval;
	};
	long double li = 0.0, ri = INF;
	int plv = calc(li), prv = calc(ri), res = max(plv, prv);
	while (abs(ri-li) > EPS) {
		long double cl = li + (ri-li) / 3.0, cr = ri - (ri-li) / 3.0;
		int lv = calc(cl), rv = calc(cr);
		res = max({ res, lv, rv });
		if (min(lv, rv) >= max(plv, prv)) {
			if (lv <= rv) {
				li = cl;
				plv = lv;
			}
			else {
				ri = cr;
				prv = rv;
			}
		}
		else {
			if (plv >= prv) {
				ri = cr;
				prv = rv;
			}
			else {
				li = cl;
				plv = lv;
			}
		}
	}
	cout << res << endl;
	return 0;
}
