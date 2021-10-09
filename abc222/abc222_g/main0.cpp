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

// 本番実装,未完成

using mint = dynamic_modint<0>;

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll k;
		cin >> k;
		mint::set_mod(9*k/2);
		mint rval = 10;
		int res = -1, ncnt = 1;
		while ((ll)ncnt < min((ll)(2e5), k*10)) {
			mint nval = rval - (mint(9) * k / 2 + 1);
			if (nval.val() == 0) {
				res = ncnt;
				break;
			}
			rval *= 10;
			++ncnt;
		}
		cout << res << endl;
	}
	return 0;
}
