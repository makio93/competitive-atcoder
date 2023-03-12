// 本番WA1

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

const ll LINF = (ll)(1e12);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		vector<ll> x(3);
		rep(i, 3) cin >> x[i];
		sort(all(x));
		ll mval = x[0];
		rep(i, 3) x[i] -= mval;
		bool ok = true;
		rep(i, 3) if (x[i]%2 != 0) {
			ok = false;
			break;
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		ll res = 0;
		while (x[2]-x[0] >= 4) {
			if (x[0]!=x[1] && x[1]!=x[2]) {
				ll cval = min((x[2]-x[1])/2, (x[2]-x[0])/4);
				res += cval;
				x[0] += cval * 7;
				x[1] += cval * 5;
				x[2] += cval * 3;
			}
			else {
				if (x[1] == x[2]) {
					x[0] += 7;
					x[2] += 5;
					x[1] += 3;
				}
				else {
					x[0] += 5;
					x[1] += 7;
					x[2] += 3;
				}
				++res;
			}
			sort(all(x));
			ll tval = x[0];
			rep(i, 3) x[i] -= tval;
		}
		if (x[2] == x[0]) cout << res << endl;
		else cout << -1 << endl;
	}
	return 0;
}
