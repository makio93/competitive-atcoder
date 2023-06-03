// 自力AC

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
pair<int, int> op(pair<int, int> ai, pair<int, int> bi) { return { ai.first + bi.first, ai.second + bi.second }; }
pair<int, int> e() { return { 0, 0 }; }
pair<int, int> mapping(bool f, pair<int, int> x) { return { f ? (x.second - x.first) : x.first, x.second }; }
bool composition(bool f, bool g) { return f ? !g : g; }
bool id() { return false; }

int main() {
	int q;
	cin >> q;
	vector<int> a(q), b(q), c(q), d(q);
	rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
	vector<tuple<int, int, int, bool>> ylst;
	rep(i, q) {
		ylst.emplace_back(b[i], a[i], c[i], false);
		ylst.emplace_back(d[i], a[i], c[i], true);
	}
	sort(all(ylst));
	vector<int> xlst;
	rep(i, q) {
		xlst.push_back(a[i]);
		xlst.push_back(c[i]);
	}
	sort(all(xlst));
	xlst.erase(unique(all(xlst)), xlst.end());
	int m = xlst.size();
	rep(i, q*2) {
		get<1>(ylst[i]) = lower_bound(all(xlst), get<1>(ylst[i])) - xlst.begin();
		get<2>(ylst[i]) = lower_bound(all(xlst), get<2>(ylst[i])) - xlst.begin();
	}
	lazy_segtree<pair<int, int>, op, e, bool, mapping, composition, id> lst(m);
	rep(i, m-1) lst.set(i, { 0, xlst[i+1] - xlst[i] });
	ll res = 0;
	rep(i, q*2-1) {
		lst.apply(get<1>(ylst[i]), get<2>(ylst[i]), true);
		res += (get<0>(ylst[i+1]) - get<0>(ylst[i])) * (ll)lst.all_prod().first;
	}
	cout << res << endl;
	return 0;
}
