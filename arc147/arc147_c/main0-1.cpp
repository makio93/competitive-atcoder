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

const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> l(n), r(n);
	rep(i, n) cin >> l[i] >> r[i];
	vector<int> clst(n);
	rep(i, n) clst[i] = l[i] + r[i];
	vector<tuple<int, int, int>> ttmp(n);
	rep(i, n) ttmp[i] = { clst[i], l[i], r[i] };
	sort(all(ttmp));
	rep(i, n) {
		clst[i] = get<0>(ttmp[i]);
		l[i] = get<1>(ttmp[i]);
		r[i] = get<2>(ttmp[i]);
	}
	int lval = (n%2==1) ? (clst[n/2]/2) : ((clst[n/2-1]+clst[n/2])/4), 
		rval = (n%2==1) ? ((clst[n/2]+1)/2) : ((clst[n/2-1]+clst[n/2]+3)/4);
	ll res = LINF;
	for (int tval=lval; tval<=rval; ++tval) {
		vector<int> xvals(n);
		rep(i, n) {
			xvals[i] = tval;
			xvals[i] = min(xvals[i], r[i]);
			xvals[i] = max(xvals[i], l[i]);
		}
		sort(all(xvals));
		vector<ll> xsums(n+1);
		rep(i, n) xsums[i+1] += xsums[i] + xvals[i];
		ll sval = 0;
		rep(i, n) sval += (ll)xvals[i] * i - xsums[i];
		res = min(res, sval);
	}
	cout << res << endl;
	return 0;
}
