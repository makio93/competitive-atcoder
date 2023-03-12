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

const int INF = (int)(1e9);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		vector<ll> x(3);
		rep(i, 3) cin >> x[i];
		bool ok = true;
		rep3(i, 1, 3) if (x[i]%2 != x[0]%2) {
			ok = false;
			break;
		}
		if (!ok) {
			cout << -1 << endl;
			continue;
		}
		ll mval = *min_element(all(x));
		rep(i, 3) x[i] -= mval;
		rep(i, 3) x[i] /= 2;
		ll sval = accumulate(all(x), 0LL);
		if (sval%3 != 0) {
			cout << -1 << endl;
			continue;
		}
		sval /= 3;
		ll res = 0;
		rep(i, 3) res += max(0LL, sval-x[i]);
		cout << res << endl;
	}
	return 0;
}
