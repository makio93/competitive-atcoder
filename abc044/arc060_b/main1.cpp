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
	auto calc = [](ll nval, ll bval) -> ll {
		ll rval = 0;
		while (nval > 0) {
			rval += nval % bval;
			nval /= bval;
		}
		return rval;
	};
	for (ll b=2; b*b<=n; ++b) if (calc(n, b) == s) {
		cout << b << endl;
		return 0;
	}
	ll res = LINF;
	auto check = [](ll a, ll n, ll s) -> ll {
		if (s < a) return -1;
		ll a1 = s - a;
		if ((n-a1)%a != 0) return -1;
		ll b = (n-a1) / a;
		if (b<=a || b<=a1) return -1;
		return b;
	};
	for (ll a=1; a*(a-1)<=n; ++a) {
		ll rval = check(a, n, s);
		if (rval != -1) res = min(res, rval);
	}
	if (res == LINF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
