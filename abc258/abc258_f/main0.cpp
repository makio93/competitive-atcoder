// 本番WA

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll b, k, sx, sy, gx, gy;
		cin >> b >> k >> sx >> sy >> gx >> gy;
		vector<pair<ll, pair<ll, ll>>> slst, glst;
		auto makelist = [&](vector<pair<ll, pair<ll, ll>>>& lst, ll xi, ll yi) -> void {
			ll xval = xi % b, yval = yi % b;
			ll xdist = xval * k, x0 = xi/b*b, y0 = yi;
			ll yl = y0 / b * b, yr = (y0/b+1) * b;
			lst.emplace_back(xdist+abs(yl-y0), make_pair(x0, yl));
			lst.emplace_back(xdist+abs(yr-y0), make_pair(x0, yr));
			xdist = (b-xval)*k, x0 = (xi/b+1)*b, y0 = yi;
			yl = y0 / b * b, yr = (y0/b+1) * b;
			lst.emplace_back(xdist+abs(yl-y0), make_pair(x0, yl));
			lst.emplace_back(xdist+abs(yr-y0), make_pair(x0, yr));
			ll ydist = yval*k, x1 = xi, y1 = yi/b*b;
			ll xl = x1 / b * b, xr = (y1/b+1) * b;
			lst.emplace_back(ydist+abs(xl-x1), make_pair(xl, y1));
			lst.emplace_back(ydist+abs(xr-x1), make_pair(xr, y1));
			ydist = (b-yval)*k, x1 = xi, y1 = (yi/b+1)*b;
			xl = x1 / b * b, xr = (y1/b+1) * b;
			lst.emplace_back(ydist+abs(xl-x1), make_pair(xl, y1));
			lst.emplace_back(ydist+abs(xr-x1), make_pair(xr, y1));
		};
		makelist(slst, sx, sy);
		makelist(glst, gx, gy);
		ll res = (llabs(sx-gx) + llabs(sy-gy)) * k;
		rep(i, 8) rep(j, 8) {
			ll val = slst[i].first + glst[j].first;
			val += llabs((ll)slst[i].second.first-glst[j].second.first);
			val += llabs((ll)slst[i].second.second-glst[j].second.second);
			res = min(res, val);
		}
		cout << res << endl;
	}
	return 0;
}
