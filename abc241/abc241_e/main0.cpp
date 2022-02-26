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

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	vector<ll> xsum(n);
	rep(i, n) cin >> a[i];
	ll x = 0;
	vector<int> rcnt(n, -1);
	rep(i, (int)(min(k,(ll)2*n))) {
		if (rcnt[(int)(x%n)] != -1) {
			int rlen = i - rcnt[(int)(x%n)];
			ll sval = x - xsum[(int)(x%n)];
			int lval = (int)(x%n);
			ll lsum = xsum[(int)(x%n)];
			x += (k-i) / rlen * sval;
			int rk = (int)((k-i) % rlen), nval = lval;
			rep(j, rk) nval = (nval + a[nval]) % n;
			ll rsum = xsum[nval];
			x += rsum - lsum;
			break;
		}
		rcnt[(int)(x%n)] = i;
		xsum[(int)(x%n)] = x;
		x += a[(int)(x%n)];
	}
	cout << x << endl;
	return 0;
}
