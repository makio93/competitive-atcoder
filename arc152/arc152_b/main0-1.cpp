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
const ll LINF = (ll)(1e18);

int main() {
	int n;
	ll l;
	cin >> n >> l;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	auto ra = a;
	reverse(all(ra));
	rep(i, n) ra[i] = l - ra[i];
	ll res = LINF;
	auto calc = [&](int li, int ri, vector<ll>& ta) -> ll {
		ll aval = max((ta[li]*2+(ta[ri]-ta[li])), ((l-ta[ri])*2));
		ll rval = LINF;
		ll d = ta[ri], t = l - d;
		int nli = upper_bound(all(ta), t) - ta.begin();
		if (nli-1 >= 0) {
			ll bval = max((ta[nli-1]*2+(ta[ri]-ta[nli-1])), ((l-ta[ri])*2+(ta[ri]-ta[nli-1])));
			ll cval = max(ta[nli-1]-ta[li], ta[ri]-ta[nli-1]);
			rval = min(rval, aval+bval+cval);
		}
		if (nli < n) {
			ll bval = max((ta[nli]*2+(ta[ri]-ta[nli])), ((l-ta[ri])*2+(ta[ri]-ta[nli])));
			ll cval = max(ta[nli]-ta[li], ta[ri]-ta[nli]);
			rval = min(rval, aval+bval+cval);
		}
		return rval;
	};
	rep(i, n) {
		ll d = (ll)l * 2 / 3 - a[i] / 3;
		if (a[i] > l-d) continue;
		int lid = upper_bound(all(a), d) - a.begin();
		if (lid-1 >= i) {
			res = min(res, calc(i, lid-1, a));
		}
		if (lid>=i && lid<n) {
			res = min(res, calc(i, lid, a));
		}
	}
	rep(i, n) {
		ll d = (ll)l * 2 / 3 - ra[i] / 3;
		if (ra[i] > l-d) continue;
		int lid = upper_bound(all(ra), d) - ra.begin();
		if (lid-1 >= i) {
			res = min(res, calc(i, lid-1, ra));
		}
		if (lid>=i && lid<n) {
			res = min(res, calc(i, lid, ra));
		}
	}
	res = res / 2 * 2;
	cout << res << endl;
	return 0;
}
