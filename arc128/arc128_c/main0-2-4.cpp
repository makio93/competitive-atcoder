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

// 自力WA4

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> rsum(n+1);
	repr(i, n) rsum[i] = rsum[i+1] + a[i];
	vector<pair<long double, int>> rvals(n+1);
	rvals[n] = { 0, n };
	repr(i, n) rvals[i] = { (long double)rsum[i]/(n-i), -i };
	sort(rvals.rbegin(), rvals.rend());
	rep(i, n+1) rvals[i].second *= -1;
	int lid = n - s / m;
	map<int, double> xvals;
	int tid = n, rid = 0;
	while (tid > 0) {
		bool br = false;
		while (rid<n && rvals[rid].second>=tid) ++rid;
		int nid = rvals[rid].second;
		if (rid>=n || rvals[rid].second>=tid) {
			xvals[n-1] = (double)m;
			if (lid-1 >= 0) xvals[lid-1] = (double)(s%m);
			if (lid-2 >= 0) xvals[lid-2] = 0.0;
			break;
		}
		if (nid >= lid) xvals[n-1] = (double)m;
		else {
			vector<pair<long double, int>> rvals2(tid+1);
			repr(i, tid) rvals2[i] = { (long double)(rsum[i]-rsum[tid])/(tid-i), -i };
			sort(rvals2.rbegin(), rvals2.rend());
			rep(i, tid+1) rvals2[i].second *= -1;
			int s2 = s - (ll)(n-tid)*m, lid2 = tid - s2 / m;
			int tid2 = tid, rid2 = 0;
			while (tid2 > 0) {
				while (rid2<tid && rvals2[rid2].second>=tid2) ++rid2;
				int nid2 = rvals2[rid2].second;
				if (rid2>=tid || rvals2[rid2].second>=tid2) {
					xvals[tid-1] = (double)m;
					if (lid2-1 >= 0) xvals[lid2-1] = (double)(s2%m);
					if (lid2-2 >= 0) xvals[lid2-2] = 0.0;
					br = true;
					break;
				}
				if (nid2 >= lid2) xvals[tid-1] = (double)m;
				else {
					double xi = (s2-(ll)m*(tid-tid2)) / double(tid2-nid2);
					xvals[tid2-1] = xi;
					xvals[nid2-1] = 0.0;
					br = true;
					break;
				}
			}
			if (br) break;
		}
		tid = nid;
		if (tid < lid) break;
	}
	long double res = 0.0;
	int tmp = 0;
	for (auto pi : xvals) {
		long double xval = pi.second;
		ll asum = 0;
		rep3(i, tmp, pi.first+1) asum += a[i];
		res += asum * xval;
		tmp = pi.first + 1;
	}
	printf("%.14Lf\n", res);
	return 0;
}
