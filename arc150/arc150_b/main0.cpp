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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll a, b;
		cin >> a >> b;
		ll res = LINF;
		if (a <= (ll)ceil(sqrt(b))) {
			for (ll x=0; x<a; ++x) {
				ll ma = a + x, mb = (b+ma-1) / ma * ma, y = mb - b;
				res = min(res, x+y);
			}
		}
		else if (a <= b) {
			ll mi = (b+a-1) / a;
			while (mi > 0) {
				ll mb = max(a, (b+mi-1)/mi) * mi, ma = mb / mi, x = ma - a, y = mb - b;
				res = min(res, x+y);
				--mi;
			}
		}
		else res = min(res, a-b);
		cout << res << endl;
	}
	return 0;
}
