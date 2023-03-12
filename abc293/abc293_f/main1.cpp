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
		ll n;
		cin >> n;
		unordered_set<ll> st;
		st.insert(n);
		if (n-1 >= 2) st.insert(n-1);
		st.insert(2);
		if (n <= 3) {
			cout << (int)(st.size()) << endl;
			continue;
		}
		int ri = 0;
		while (n >= 1LL<<ri) ++ri;
		rep3(i, 3, ri) {
			ll lval = 2, rval = n;
			while (rval-lval > 1) {
				ll cval = lval + (rval-lval) / 2;
				bool big = false;
				ll tval = 1;
				rep(j, i-1) {
					if (tval > n/cval) {
						big = true;
						break;
					}
					tval *= cval;
				}
				if (big) {
					rval = cval;
					continue;
				}
				tval = 1;
				rep(j, i-1) {
					if (tval >= (n-1)/cval) {
						big = true;
						break;
					}
					tval = tval * cval + 1;
				}
				if (big) lval = cval;
				else lval = cval + 1;
			}
			if (lval >= rval) continue;
			bool ok = true;
			ll nval = n;
			while (nval > 0) {
				if (nval%lval > 1) {
					ok = false;
					break;
				}
				nval /= lval;
			}
			if (ok) st.insert(lval);
		}
		cout << (int)(st.size()) << endl;
	}
	return 0;
}
