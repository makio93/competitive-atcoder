// 解説AC:pair<val,id>でなくmultiset<val>でOK

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
	int n, q;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	cin >> q;
	vector<int> l(q), r(q);
	rep(i, q) {
		cin >> l[i] >> r[i];
		l[i]--;
	}
	int sq = (int)ceil(sqrt(q));
	vector<int> ord(q);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		if (l[li]/sq != l[ri]/sq) return l[li]/sq < l[ri]/sq;
		else if (l[li]/sq%2 == 0) return r[li] < r[ri];
		else return r[li] > r[ri];
	});
	ll nval = 0;
	vector<ll> res(q);
	multiset<int> ast;
	function<void(int)> add = [&](int val) {
		ast.insert(val);
		if ((int)(ast.size()) <= 1) return;
		auto itr = ast.find(val);
		if (itr == ast.begin()) nval += (*next(itr) - *itr) * (ll)(*next(itr) - *itr);
		else if (next(itr) == ast.end()) nval += (*itr - *prev(itr)) * (ll)(*itr - *prev(itr));
		else {
			nval -= (*next(itr) - *prev(itr)) * (ll)(*next(itr) - *prev(itr));
			nval += (*next(itr) - *itr) * (ll)(*next(itr) - *itr);
			nval += (*itr - *prev(itr)) * (ll)(*itr - *prev(itr));
		}
	};
	function<void(int)> del = [&](int val) {
		auto itr = ast.find(val);
		if ((int)(ast.size()) >= 2) {
			if (itr == ast.begin()) nval -= (*next(itr) - *itr) * (ll)(*next(itr) - *itr);
			else if (next(itr) == ast.end()) nval -= (*itr - *prev(itr)) * (ll)(*itr - *prev(itr));
			else {
				nval += (*next(itr) - *prev(itr)) * (ll)(*next(itr) - *prev(itr));
				nval -= (*next(itr) - *itr) * (ll)(*next(itr) - *itr);
				nval -= (*itr - *prev(itr)) * (ll)(*itr - *prev(itr));
			}
		}
		ast.erase(itr);
	};
	int lv = 0, rv = 0;
	rep(i, q) {
		while (rv < r[ord[i]]) {
			add(a[rv]);
			++rv;
		}
		while (lv < l[ord[i]]) {
			del(a[lv]);
			++lv;
		}
		while (lv > l[ord[i]]) {
			--lv;
			add(a[lv]);
		}
		while (rv > r[ord[i]]) {
			--rv;
			del(a[rv]);
		}
		res[ord[i]] = nval;
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
