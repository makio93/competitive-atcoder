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

// 本番WA

using mint1 = dynamic_modint<1>;
using mint = modint998244353;
const ll mod = 998244353LL;

int main() {
	ll n, k, m;
	cin >> n >> k >> m;
	if (m == 1) {
		cout << 1 << endl;
		return 0;
	}
	bool ok = true;
	ll rcnt = 1;
	if (k > 1) {
		for (ll i=0; i<n; ++i) {
			if (rcnt < (mod+k-1)/k) rcnt *= k;
			else {
				ok = false;
				break;
			}
		}
	}
	mint res = m;
	if (ok) {
		res = res.pow(rcnt);
	}
	else {
		mint1::set_mod(mod-1);
		mint1 rval = k;
		rval = rval.pow(n);
		res = res.pow(rval.val());
	}
	cout << res.val() << endl;
	return 0;
}
