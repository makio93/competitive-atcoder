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
	int n, k, xs, ys, xt, yt;
	cin >> n >> k >> xs >> ys >> xt >> yt;
	vector<int> p(n), q(n), r(n), w(n);
	rep(i, n) cin >> p[i] >> q[i] >> r[i] >> w[i];
	vector<int> wlst(n);
	rep(i, n) {
		ll sval = (ll)p[i] * xs + (ll)q[i] * ys - r[i], tval = (ll)p[i] * xt + (ll)q[i] * yt - r[i];
		sval = min(1LL, max(-1LL, sval));
		tval = min(1LL, max(-1LL, tval));
		if (sval*tval <= 0) wlst[i] = w[i];
	}
	sort(all(wlst));
	ll res = 0;
	rep(i, k) res += wlst[i];
	cout << res << endl;
	return 0;
}
