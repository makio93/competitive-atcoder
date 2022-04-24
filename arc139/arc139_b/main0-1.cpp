// 

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

ll mygcd(ll a, ll b) { return (b ? mygcd(b, a%b) : a); }
ll mylcm(ll a, ll b) { return (a / mygcd(a, b) * b); }

int main() {
	int ti;
	cin >> ti;
	rep(i0, ti) {
		ll n, a, b, x, y, z;
		cin >> n >> a >> b >> x >> y >> z;
		ll lval = mylcm(a, b);
		ll res = n * x;
		ll am = n % a, bm = n % b;
		ll aval = n / a * a, bval = n / b * b;
		res = min({ res, am*x+aval/a*y, bm*x+bval/b*z });
		if (lval <= aval) {
			ll asub = aval - lval;
			res = min(res, am*x+asub/a*y+lval/b*z);
		}
		if (lval <= bval) {
			ll bsub = bval - lval;
			res = min(res, bm*x+bsub/b*z+lval/a*y);
		}
		cout << res << endl;
	}
	return 0;
}
