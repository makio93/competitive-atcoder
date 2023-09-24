// 自力AC

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
		ll n, x, k;
		cin >> n >> x >> k;
		function<ll(ll, ll)> f = [&](ll vi, ll di) {
			if (vi > n) return 0LL;
			if (di == 0) return 1LL;
			ll li = vi;
			for (ll i=0; i<di; ++i) {
				li *= 2;
				if (li > n) return 0LL;
			}
			ll ri = vi;
			for (ll i=0; i<di; ++i) ri = ri * 2 + 1;
			if (ri > n) return n - li + 1;
			else return ri - li + 1;
		};
		ll res = f(x, k);
		while (x/2 >= 1 && k >= 2) {
			if (x%2 == 1) res += f(x-1, k-2);
			else res += f(x+1, k-2);
			x /= 2; --k;
		}
		if (k == 1 && x/2 >= 1) ++res;
		cout << res << endl;
	}
	return 0;
}
