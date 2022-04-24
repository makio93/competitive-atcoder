// 

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

ll mygcd(ll a, ll b) { return (b ? mygcd(b, a%b) : a); }
ll mylcm(ll a, ll b) { return (a / mygcd(a, b) * b); }

int main() {
	int ti;
	cin >> ti;
	rep(i0, ti) {
		ll n, a, b, x, y, z;
		cin >> n >> a >> b >> x >> y >> z;
		ll l = 0, r = n / a;
		auto calc = [&](ll aval) -> ll {
			ll sub = n - aval * a;
			ll bval = min(sub*x, sub/b*z+sub%b*x);
			return bval + aval * y;
		};
		ll res = min({ n*x, calc(l), calc(r) });
		if (r < (ll)(round(sqrt(n)))*100) {
			for (ll c=l; c<=r; ++c) res = min(res, calc(c));
		}
		else {
		while (r-l > 0) {
			if (r-l <= 2) {
				pair<ll, ll> val = { calc(l), l };
				for (ll c=l+1; c<=r; ++c) val = min(val, { calc(c), c });
				l = val.second;
				res = min(res, calc(l));
				break;
			}
			else {
				ll cl = l + (r-l) / 3, cr = r - (r-l) / 3;
				ll clval = calc(cl), crval = calc(cr);
				res = min({ res, clval, crval });
				if (clval >= crval) l = cl;
				else r = cr;
			}
		}
		}
		l = 0; r = n / b;
		auto calc2 = [&](ll bval) -> ll {
			ll sub = n - bval * b;
			ll aval = min(sub*x, sub/a*y+sub%a*x);
			return aval + bval * z;
		};
		res = min(calc2(l), calc2(r));
		if (r < (ll)(round(sqrt(n)))*100) {
			for (ll c=l; c<=r; ++c) res = min(res, calc2(c));
		}
		else {
		while (r-l > 0) {
			if (r-l <= 2) {
				pair<ll, ll> val = { calc2(l), l };
				for (ll c=l+1; c<=r; ++c) val = min(val, { calc2(c), c });
				l = val.second;
				min(res, calc2(l));
				break;
			}
			else {
				ll cl = l + (r-l) / 3, cr = r - (r-l) / 3;
				ll clval = calc2(cl), crval = calc2(cr);
				res = min({ res, clval, crval });
				if (clval >= crval) l = cl;
				else r = cr;
			}
		}
		}
		cout << res << endl;
	}
	return 0;
}
