#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力で解答、WA

const ll BIAS = (ll)(1e9);

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
		x[i] += BIAS; y[i] += BIAS;
	}
	vector<ll> d(n), rd(n);
	rep(i, n) d[i] = rd[i] = (ll)(x[i]+y[i]);
	sort(all(rd));
	rep(i, q) {
		int qi;
		cin >> qi;
		--qi;
		ll res = max(llabs(rd.front()-d[qi]), llabs(rd.back()-d[qi]));
		cout << res << endl;
	}
	return 0;
}
