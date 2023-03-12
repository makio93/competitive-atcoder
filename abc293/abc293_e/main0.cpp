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

const int INF = (int)(1e9);
__int128_t tmp;

ll modpow_(ll a, ll b, ll m) {
	ll p = 1, q = a;
	rep(i, 63) {
		if (b & (1LL<<i)) {
			tmp = p;
			tmp *= q;
			tmp %= m;
			p = tmp;
		}
		tmp = q;
		tmp *= q;
		tmp %= m;
		q = tmp;
	}
	return p;
}

int main() {
	ll a, x, m;
	cin >> a >> x >> m;
	if (m == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (a == 1) {
		cout << (x%m) << endl;
		return 0;
	}
	ll val = modpow_(a, x, (a-1)*m) - 1;
	if (val < 0) val += (a-1)*m;
	val /= a - 1;
	val %= m;
	cout << val << endl;
	return 0;
}
