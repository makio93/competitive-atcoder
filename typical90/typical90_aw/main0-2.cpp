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

// 自力で作成、WA
// その2：一次元DPっぽく

const ll DINF = (ll)(1e15);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> c(m), l(m), r(m);
	rep(i, m) {
		cin >> c[i] >> l[i] >> r[i];
		l[i]--;
	}
	unordered_map<int, vector<pair<ll, int>>> cr;
	rep(i, m) cr[l[i]].emplace_back(c[i], r[i]);
	vector<ll> rval(n+1, DINF);
	ll res = 0;
	bool ok = true;
	rep(i, n+1) {
		ll nval1 = rval[i]; pair<ll, int> nval2 = { DINF, n+5 };
		if (nval1==DINF && cr[i].empty()) {
			ok = false;
			break;
		}
		rep(j, (int)(cr[i].size())) {
			ll ci = cr[i][j].first; int ri = cr[i][j].second;
			nval2 = min(nval2, { ci, ri });
			rval[ri] = min(rval[ri], ci);
		}
		if (nval1 < nval2.first) res += nval1;
		else {
			res += nval2.first;
			rval[nval2.second] = 0;
		}
	}
	if (ok) cout << res << endl;
	else cout << -1 << endl;
	return 0;
}
