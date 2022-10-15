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

const ll LINF = (ll)(2e18);
const ll BIG = (ll)(1e18);

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> y(n), z(n);
	rep(i, n) cin >> y[i];
	rep(i, n) cin >> z[i];
	vector<pair<int, int>> lst;
	lst.emplace_back(0, 0);
	lst.emplace_back(x, 0);
	rep(i, n) lst.emplace_back(y[i], i+1);
	rep(i, n) lst.emplace_back(z[i], -(i+1));
	sort(all(lst));
	int sid = -1;
	rep(i, n*2+2) if (lst[i].first == 0) {
		sid = i;
		break;
	}
	vector<vector<vector<ll>>> memo(n*2+2, vector<vector<ll>>(n*2+2, vector<ll>(2, LINF)));
	auto calc = [&](auto calc, int li, int ri, int di) -> ll {
		if (memo[li][ri][di] != LINF) return memo[li][ri][di];
		ll rval = BIG;
		if (di == 0) {
			if (lst[li].first!=0 && lst[li].second==0) rval = 0;
			else {
				if (li-1 >= 0) {
					bool ok = true;
					if (lst[li-1].second > 0) {
						int zid = z[lst[li-1].second-1];
						if (zid<lst[li].first || zid>lst[ri].first) ok = false;
					}
					if (ok) {
						ll dist = abs(lst[li-1].first-lst[li].first);
						rval = min(rval, calc(calc,li-1,ri,0)+dist);
					}
				}
				if (ri+1 < n*2+2) {
					bool ok = true;
					if (lst[ri+1].second > 0) {
						int zid = z[lst[ri+1].second-1];
						if (zid<lst[li].first || zid>lst[ri].first) ok = false;
					}
					if (ok) {
						ll dist = abs(lst[ri+1].first-lst[li].first);
						rval = min(rval, calc(calc,li,ri+1,1)+dist);
					}
				}
			}
		}
		else {
			if (lst[ri].first!=0 && lst[ri].second==0) rval = 0;
			else {
				if (li-1 >= 0) {
					bool ok = true;
					if (lst[li-1].second > 0) {
						int zid = z[lst[li-1].second-1];
						if (zid<lst[li].first || zid>lst[ri].first) ok = false;
					}
					if (ok) {
						ll dist = abs(lst[li-1].first-lst[ri].first);
						rval = min(rval, calc(calc,li-1,ri,0)+dist);
					}
				}
				if (ri+1 < n*2+2) {
					bool ok = true;
					if (lst[ri+1].second > 0) {
						int zid = z[lst[ri+1].second-1];
						if (zid<lst[li].first || zid>lst[ri].first) ok = false;
					}
					if (ok) {
						ll dist = abs(lst[ri+1].first-lst[ri].first);
						rval = min(rval, calc(calc,li,ri+1,1)+dist);
					}
				}
			}
		}
		return memo[li][ri][di] = rval;
	};
	ll res = calc(calc, sid, sid, 0);
	if (res == BIG) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
