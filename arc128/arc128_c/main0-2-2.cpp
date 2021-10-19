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

// 自力WA2

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> rsum(n+1);
	repr(i, n) rsum[i] = rsum[i+1] + a[i];
	vector<pair<ll, int>> rvals(n+1);
	rvals[n] = { 0, n };
	repr(i, n) rvals[i] = { rsum[i]*n/(n-i), i };
	sort(rvals.rbegin(), rvals.rend());
	int lid = n - s / m;
	vector<double> xvals(n, 0.0);
	int tid = n, rid = 0, mid = n;
	while (tid > 0) {
		while (rid<n && rvals[rid].second>=tid) ++rid;
		int nid = rvals[rid].second;
		if (rid>=n || rvals[rid].second>=tid) {
			mid = lid;
			if (lid-1 >= 0) xvals[lid-1] = round(s%m);
			break;
		}
		if (nid >= lid) mid = nid;
		else {
			double xi = (s-(ll)m*(n-tid)) / round(tid-nid);
			rep3r(i, nid, tid) xvals[i] = xi;
		}
		tid = nid;
		if (tid < lid) break;
	}
	double res = 0.0;
	rep(i, mid) res += (xvals[i]) * round(a[i]);
	rep3(i, mid, n) res += round((ll)m*a[i]);
	printf("%.14f\n", res);
	return 0;
}
