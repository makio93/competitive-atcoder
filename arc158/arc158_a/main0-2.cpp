// 本番WA2

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
		rep(i, 3) x[i] /= 2;
		if (x[1]*2 < x[2]) {
			x[0] = x[2];
			x[1] = x[2] - x[1];
			x[2] = 0;
			sort(all(x));
		}
		ll res = (x[1] + x[2]) / 3;
		cout << res << endl;
	}
	return 0;
}
