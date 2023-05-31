// 自力AC:バチャ本番ではWA，終了後に値が途中でオーバーフローしていた部分を修正

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
	set<pair<int, int>> ast;
	function<void(int,int)> add = [&](int val, int id) {
		ast.emplace(val, id);
		if ((int)(ast.size()) <= 1) return;
		auto itr = ast.find({ val, id });
		if (itr == ast.begin()) nval += (next(itr)->first - itr->first) * (ll)(next(itr)->first - itr->first);
		else if (next(itr) == ast.end()) nval += (itr->first - prev(itr)->first) * (ll)(itr->first - prev(itr)->first);
		else {
			nval -= (next(itr)->first - prev(itr)->first) * (ll)(next(itr)->first - prev(itr)->first);
			nval += (next(itr)->first - itr->first) * (ll)(next(itr)->first - itr->first);
			nval += (itr->first - prev(itr)->first) * (ll)(itr->first - prev(itr)->first);
		}
	};
	function<void(int,int)> del = [&](int val, int id) {
		auto itr = ast.find({ val, id });
		if ((int)(ast.size()) >= 2) {
			if (itr == ast.begin()) nval -= (next(itr)->first - itr->first) * (ll)(next(itr)->first - itr->first);
			else if (next(itr) == ast.end()) nval -= (itr->first - prev(itr)->first) * (ll)(itr->first - prev(itr)->first);
			else {
				nval += (next(itr)->first - prev(itr)->first) * (ll)(next(itr)->first - prev(itr)->first);
				nval -= (next(itr)->first - itr->first) * (ll)(next(itr)->first - itr->first);
				nval -= (itr->first - prev(itr)->first) * (ll)(itr->first - prev(itr)->first);
			}
		}
		ast.erase(itr);
	};
	int lv = 0, rv = 0;
	rep(i, q) {
		while (rv < r[ord[i]]) {
			add(a[rv], rv);
			++rv;
		}
		while (lv < l[ord[i]]) {
			del(a[lv], lv);
			++lv;
		}
		while (lv > l[ord[i]]) {
			--lv;
			add(a[lv], lv);
		}
		while (rv > r[ord[i]]) {
			--rv;
			del(a[rv], rv);
		}
		res[ord[i]] = nval;
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
