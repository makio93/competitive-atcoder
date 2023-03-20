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
	int n, m;
	ll k;
	cin >> n >> m >> k;
	vector<int> a(n), b(n), c(m), d(m);
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, m) cin >> c[i] >> d[i];
	long double lv = 0.0, rv = 1.0;
	vector<long double> dvals;
	while ((rv-lv)/rv > 1e-12) {
		long double cv = lv + (rv-lv) / 2.0;
		dvals.assign(m, 0.0);
		rep(i, m) dvals[i] = (1.0-cv) * c[i] - cv * d[i];
		sort(all(dvals));
		ll cnt = 0;
		rep(i, n) {
			long double tval = (cv-1.0) * a[i] + cv * b[i];
			cnt += dvals.end() - lower_bound(all(dvals), tval);
		}
		if (cnt >= k) lv = cv;
		else rv = cv;
	}
	long double res = lv * 100.0;
	printf("%.14Lf\n", res);
	return 0;
}
