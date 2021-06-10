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

// 自力AC

const ll BIAS = (ll)(1e9);

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> x(n), y(n);
	rep(i, n) {
		cin >> x[i] >> y[i];
		x[i] += BIAS; y[i] += BIAS;
	}
	vector<ll> ad(n), adr(n), bd(n), bdr(n);
	rep(i, n) ad[i] = adr[i] = (ll)(x[i]+y[i]);
	rep(i, n) bd[i] = bdr[i] = (ll)(x[i]-y[i]);
	sort(all(adr)); sort(all(bdr));
	rep(i, q) {
		int qi;
		cin >> qi;
		--qi;
		ll res = max({llabs(adr[0]-ad[qi]), llabs(adr[n-1]-ad[qi]), llabs(bdr[0]-bd[qi]), llabs(bdr[n-1]-bd[qi])});
		cout << res << endl;
	}
	return 0;
}
