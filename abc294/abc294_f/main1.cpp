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
	int n, m;
	ll k;
	cin >> n >> m >> k;
	vector<int> a(n), b(n), c(m), d(m);
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, m) cin >> c[i] >> d[i];
	double lv = 0.0, rv = 1.0;
	vector<double> dvals;
	while ((rv-lv)/rv > 1e-11) {
		double cv = lv + (rv-lv) / 2.0;
		dvals.assign(m, 0.0);
		rep(i, m) dvals[i] = c[i] - d[i] * cv / (1.0-cv);
		sort(all(dvals));
		ll cnt = 0;
		rep(i, n) {
			double tval = a[i] - b[i] * cv / (1.0-cv);
			cnt += dvals.end() - lower_bound(all(dvals), -tval);
		}
		if (cnt >= k) lv = cv;
		else rv = cv;
	}
	cout << fixed << setprecision(15) << (lv*100.0) << endl;
	return 0;
}
