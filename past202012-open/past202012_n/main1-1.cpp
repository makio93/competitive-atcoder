// 解説AC1

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
	vector<int> l(n-1), r(n-1), a(q), b(q);
	rep(i, n-1) cin >> l[i] >> r[i];
	rep(i, q) {
		cin >> a[i] >> b[i];
		b[i]--;
	}
	vector<int> alst;
	alst.insert(alst.end(), all(l));
	alst.insert(alst.end(), all(r));
	alst.insert(alst.end(), all(a));
	sort(all(alst));
	alst.erase(unique(all(alst)), alst.end());
	int m = alst.size();
	rep(i, n-1) l[i] = lower_bound(all(alst), l[i]) - alst.begin();
	rep(i, n-1) r[i] = lower_bound(all(alst), r[i]) - alst.begin();
	rep(i, q) a[i] = lower_bound(all(alst), a[i]) - alst.begin();
	set<int> bans;
	bans.insert(-1);
	bans.insert(n-1);
	rep(i, n-1) if (-1 < l[i]) bans.insert(i);
	vector<int> ord(q), res(q);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return a[li] < a[ri]; });
	vector<pair<pair<int, bool>, int>> lr;
	rep(i, n-1) {
		lr.emplace_back(make_pair(l[i], false), i);
		lr.emplace_back(make_pair(r[i], true), i);
	}
	sort(all(lr));
	int qi = 0, ri = 0, rlen = lr.size();
	rep(i, m) {
		while (ri < rlen && lr[ri].first == make_pair(i, false)) {
			bans.erase(lr[ri].second);
			++ri;
		}
		while (qi < q && a[ord[qi]] == i) {
			auto itr = bans.lower_bound(b[ord[qi]]);
			res[ord[qi]] = *itr - *prev(itr);
			++qi;
		}
		while (ri < rlen && lr[ri].first == make_pair(i, true)) {
			bans.insert(lr[ri].second);
			++ri;
		}
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
