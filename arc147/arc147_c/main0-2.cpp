// 本番AC

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
	vector<int> clst;
	rep(i, n) {
		clst.push_back(l[i]);
		clst.push_back(r[i]);
	}
	sort(all(clst));
	int lval = clst[n-1], rval = clst[n], cval = (lval+rval) / 2;
	ll res = LINF;
	for (int tval : { lval, rval, cval }) {
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
