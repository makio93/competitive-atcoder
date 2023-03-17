// 学習1回目,バチャ本番,自力AC

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

const ll LINF = (ll)(1e15);

int main() {
	int n, q;
	cin >> n;
	vector<int> a(n), t(n);
	rep(i, n) cin >> a[i] >> t[i];
	cin >> q;
	vector<int> x(q);
	rep(i, q) cin >> x[i];
	ll lval = -LINF, rval = LINF, dval = 0;
	set<pair<ll, int>> xst;
	rep(i, q) xst.emplace(x[i], i);
	vector<bool> lids(q), rids(q);
	rep(i, n) {
		if (t[i] == 1) dval += a[i];
		else if (t[i] == 2) {
			if (a[i] <= lval+dval) continue;
			lval += a[i] - (lval+dval);
			auto litr = xst.begin();
			while (!xst.empty() && litr->first<=lval) {
				lids[litr->second] = true;
				litr = xst.erase(litr);
			}
			if (rval < lval) rval = lval;
		}
		else {
			if (a[i] >= rval+dval) continue;
			rval -= (rval+dval) - a[i];
			auto ritr = xst.end();
			while (!xst.empty() && prev(ritr)->first>=rval) {
				rids[prev(ritr)->second] = true;
				ritr = xst.erase(prev(ritr));
			}
			if (lval > rval) lval = rval;
		}
	}
	rep(i, q) {
		if (lids[i]) cout << (lval+dval) << endl;
		else if (rids[i]) cout << (rval+dval) << endl;
		else cout << (x[i]+dval) << endl;
	}
	return 0;
}
