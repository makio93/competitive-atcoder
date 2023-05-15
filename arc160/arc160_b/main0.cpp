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

const ll mod = 998244353LL;

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		ll res = 0, val = 0;
		for (int y=1; y*(y+1)<=n; ++y) {
			int z = n / y;
			if (z > y) val = (val + (ll)(z-y) * (y-1)) % mod;
		}
		res = (res + val * 6 % mod) % mod;
		val = 0;
		for (int y=1; y*y<=n; ++y) {
			int z = n / y;
			if (z > y) val = (val + (ll)(z-y)) % mod;
		}
		res = (res + val * 3 % mod) % mod;
		val = 0;
		for (int y=1; y*y<=n; ++y) {
			val = (val + (ll)(y-1)) % mod;
		}
		res = (res + val * 3 % mod) % mod;
		val = 0;
		for (int y=1; y*y<=n; ++y) ++val;
		res = (res + val) % mod;
		cout << res << endl;
	}
	return 0;
}
