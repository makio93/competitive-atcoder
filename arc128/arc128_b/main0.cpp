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

// 本番AC

const ll INF = (ll)(2e18);

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		vector<ll> vals(3);
		rep(i, 3) cin >> vals[i];
		sort(vals.rbegin(), vals.rend());
		ll res = INF;
		rep(i, 3) rep3(j, i+1, 3) if (abs(vals[i]-vals[j])%3 == 0) {
			int sid = -1;
			rep(i2, 3) if (i!=i2 && j!=i2) sid = i2;
			ll sub1 = abs(vals[i]-vals[j]) / 3;
			if (vals[sid] >= sub1) res = min(res, sub1+(vals[i]-sub1));
			else {
				ll sub2 = (sub1-vals[sid]+1) / 2, subr = vals[i]-sub1-sub2;
				res = min(res, sub1+sub2+subr);
			}
		}
		if (res == INF) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}
