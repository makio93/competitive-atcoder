// バチャ本番,自力WA

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
	ll n, s;
	cin >> n >> s;
	if (s > n) {
		cout << -1 << endl;
		return 0;
	}
	if (n == s) {
		cout << (n+1) << endl;
		return 0;
	}
	ll res = -1;
	auto calc = [](ll nval, ll bval) -> ll {
		ll rval = 0;
		while (nval > 0) {
			rval += nval % bval;
			nval /= bval;
		}
		return rval;
	};
	for (ll b=2; b*b<=n; ++b) {
		if (calc(n, b) == s) {
			res = b;
			break;
		}
	}
	ll tval = (s+1) / 2 + 1;
	if (tval > (n+1)/tval) {
		cout << res << endl;
		return 0;
	}
	auto check = [](ll a, ll n, ll s) -> ll {
		if (a == s) return -1;
		if (s <= a) return -1;
		ll a1 = s - a;
		if ((n-a)%a1 != 0) return -1;
		return (n-a) / a1;
	};
	if (res == -1) res = LINF;
	for (ll a=0; a<tval; ++a) {
		ll rval = check(a, n, s);
		if (rval != -1) {
			if (rval>=2 && rval>a && rval>s-a) res = min(res, rval);
		}
		rval = check(s-a, n, s);
		if (rval != -1) {
			if (rval>=2 && rval>a && rval>s-a) res = min(res, rval);
		}
	}
	if (res == LINF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
