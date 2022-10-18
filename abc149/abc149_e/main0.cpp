// バチャ本番AC

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
	int n;
	ll m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	int lval = 1, rval = INF;
	while (rval-lval > 1) {
		int cval = lval + (rval-lval) / 2;
		ll tcnt = 0;
		rep(i, n) {
			int id = lower_bound(all(a), cval-a[i]) - a.begin();
			tcnt += n - id;
		}
		if (tcnt >= m) lval = cval;
		else rval = cval;
	}
	vector<ll> asum(n+1);
	rep(i, n) asum[i+1] = asum[i] + a[i];
	ll res = 0, mcnt = 0;
	rep(i, n) {
		int id = lower_bound(all(a), rval-a[i]) - a.begin();
		mcnt += n - id;
		res += (asum[n] - asum[id]) + (ll)a[i] * (n - id);
	}
	if (m > mcnt) res += (ll)lval * (m-mcnt);
	cout << res << endl;
	return 0;
}
