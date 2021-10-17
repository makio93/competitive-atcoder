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

// 本番AC

int main() {
	ll x, y;
	vector<ll> a(3);
	cin >> x >> y;
	rep(i, 3) cin >> a[i];
	bool ok = false;
	{
		ll cnt = 0;
		rep(i, 3) cnt += (a[i] + y-1) / y;
		if (cnt <= x) ok = true;
	}
	if (!ok) {
		ll cnt = 0;
		rep(i, 3) cnt += (a[i] + x-1) / x;
		if (cnt <= y) ok = true;
	}
	if (!ok) {
		rep(i, 3) {
			ll val0 = (a[i] + x-1) / x, ysub = y - val0;
			if (ysub > 0) {
				ll cnt = 0;
				rep(j, 3) if (j != i) cnt += (a[j] + ysub-1) / ysub;
				if (cnt <= x) ok = true;
			}
			if (ok) break;
		}
	}
	if (!ok) {
		rep(i, 3) {
			ll val0 = (a[i] + y-1) / y, xsub = x - val0;
			if (xsub > 0) {
				ll cnt = 0;
				rep(j, 3) if (j != i) cnt += (a[j] + xsub-1) / xsub;
				if (cnt <= y) ok = true;
			}
			if (ok) break;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
