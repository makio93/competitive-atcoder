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

const ll LINF = (ll)(1e18);

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k);
	rep(i, k) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<ll> d(n, LINF);
	rep(i, k) rep(j, n) d[j] = min(d[j], (ll)(x[j]-x[a[i]])*(x[j]-x[a[i]])+(ll)(y[j]-y[a[i]])*(y[j]-y[a[i]]));
	ll mval = 0;
	rep(i, n) mval = max(mval, d[i]);
	printf("%.12f\n", sqrt(mval));
	return 0;
}
