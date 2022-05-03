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
		ll gval = mygcd(a, b);
		ll res = n * x;
		ll gm = n % gval, sval = n / gval * gval;
		ll tval = gm * x;
		ll aval = sval % a, bval = sval % b;
		ll aval2 = aval % b, bval2 = bval % a;
		res = min({ res, tval+(sval/a)*y+(aval/b)*z+aval2*x, tval+(sval/a)*y+aval*x });
		res = min({ res, tval+(sval/b)*z+(bval/a)*y+bval2*x, tval+(sval/b)*z+bval*x });
		cout << res << endl;
	}
	return 0;
}
