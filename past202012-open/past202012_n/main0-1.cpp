// 自力AC1

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
int op(int ai, int bi) { return bi == INF ? ai : bi; }
int e() { return INF; }
int mapping(int f, int x) { return f == INF ? x : f; }
int composition(int f, int g) { return f == INF ? g : f; }
int id() { return INF; }

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> l(n-1), r(n-1);
	rep(i, n-1) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	vector<int> a(q), b(q);
	rep(i, q) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	vector<int> alst;
	rep(i, n-1) alst.push_back(l[i]);
	rep(i, n-1) alst.push_back(r[i]);
	rep(i, q) alst.push_back(a[i]);
	sort(all(alst));
	alst.erase(unique(all(alst)), alst.end());
	int m = alst.size();
	rep(i, n-1) l[i] = lower_bound(all(alst), l[i]) - alst.begin();
	rep(i, n-1) r[i] = lower_bound(all(alst), r[i]) - alst.begin();
	rep(i, q) a[i] = lower_bound(all(alst), a[i]) - alst.begin();
	vector<int> ord(q);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return b[li] > b[ri];
	});
	lazy_segtree<int, op, e, int, mapping, composition, id> lst(m);
	lst.apply(0, m, n-1);
	int tid = 0;
	vector<int> res(q);
	repr(i, n) {
		if (i < n-1) {
			lst.apply(0, l[i], i);
			lst.apply(r[i]+1, m, i);
		}
		while (tid<q && b[ord[tid]]==i) {
			res[ord[tid]] = lst.get(a[ord[tid]]) - i + 1;
			++tid;
		}
	}
	reverse(all(ord));
	lst.apply(0, m, 0);
	tid = 0;
	rep(i, n) {
		if (i-1 >= 0) {
			lst.apply(0, l[i-1], i);
			lst.apply(r[i-1]+1, m, i);
		}
		while (tid<q && b[ord[tid]]==i) {
			res[ord[tid]] += i - lst.get(a[ord[tid]]);
			++tid;
		}
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
