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

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> x(n), y(n), d(n), c(n), a(q), b(q);
	rep(i, n) cin >> x[i] >> y[i] >> d[i] >> c[i];
	rep(i, q) cin >> a[i] >> b[i];
	vector<int> l(n), r(n);
	rep(i, n) {
		l[i] = x[i];
		r[i] = x[i] + d[i] + 1;
	}
	vector<int> xlst;
	rep(i, n) {
		xlst.push_back(l[i]);
		xlst.push_back(r[i]);
	}
	rep(i, q) xlst.push_back(a[i]);
	sort(all(xlst));
	xlst.erase(unique(all(xlst)), xlst.end());
	rep(i, n) {
		l[i] = lower_bound(all(xlst), l[i]) - xlst.begin();
		r[i] = lower_bound(all(xlst), r[i]) - xlst.begin();
	}
	rep(i, q) a[i] = lower_bound(all(xlst), a[i]) - xlst.begin();
	vector<int> ord(q);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return b[li] < b[ri]; });
	vector<tuple<int, int, int, int>> tlst;
	rep(i, n) {
		tlst.emplace_back(y[i], l[i], r[i], c[i]);
		tlst.emplace_back(y[i]+d[i]+1, l[i], r[i], -c[i]);
	}
	sort(all(tlst));
	int tid = 0, tlen = tlst.size(), m = xlst.size();
	vector<ll> res(q);
	fenwick_tree<ll> ft(m);
	rep(i, q) {
		while (tid<tlen && get<0>(tlst[tid])<=b[ord[i]]) {
			ft.add(get<1>(tlst[tid]), get<3>(tlst[tid]));
			ft.add(get<2>(tlst[tid]), -get<3>(tlst[tid]));
			++tid;
		}
		res[ord[i]] = ft.sum(0, a[ord[i]]+1);
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
