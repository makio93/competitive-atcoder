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

ll mygcd(ll a, ll b) { return (b ? mygcd(b, a%b) : a); }
ll mylcm(ll a, ll b) { return (a / mygcd(a, b) * b); }

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, d, k;
		cin >> n >> d >> k;
		if (k == 1) {
			cout << 0 << endl;
			continue;
		}
		--k;
		ll lval = mylcm(d, n), rval = lval / d, aval = k / rval, bval = k % rval;
		ll res = (bval % n * d % n + aval % n) % n;
		cout << res << endl;
	}
	return 0;
}
