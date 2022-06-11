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

int main() {
	ll x, a, d, n;
	cin >> x >> a >> d >> n;
	ll lval = a, rval = a + d * (n-1);
	if (lval > rval) swap(lval, rval);
	ll res = min(abs(x-lval), abs(x-rval));
	if (d!=0 && x>=lval && x<=rval) {
		ll sval = -lval;
		x += sval; lval += sval; rval += sval;
		d = abs(d);
		res = min({ res, x%d, d-x%d });
	}
	cout << res << endl;
	return 0;
}
