// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	ll n;
	cin >> n;
	ll res = (ll)(3e18);
	for (ll a=0; a<=min(n,(ll)(1e6)+1); ++a) {
		ll lb = max(0LL, a-1), rb = (ll)floor(pow(n, 1.0/3.0));
		while (rb>0 && rb*rb*rb>=n) --rb;
		while (rb*rb*rb < n) ++rb;
		while (rb-lb > 1) {
			ll cb = lb + (rb-lb) / 2;
			double dval = (double)a*a*a + a*a*cb + a*cb*cb + cb*cb*cb;
			if (dval > (double)n*2) {
				rb = cb;
				continue;
			}
			ll val = a*a*a + a*a*cb + a*cb*cb + cb*cb*cb;
			if (val >= n) rb = cb;
			else lb = cb;
		}
		res = min(res, a*a*a+a*a*rb+a*rb*rb+rb*rb*rb);
	}
	cout << res << endl;
	return 0;
}
