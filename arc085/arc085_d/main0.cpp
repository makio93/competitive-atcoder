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
int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
	int n, q;
	cin >> n;
	vector<int> b(n);
	rep(i, n) cin >> b[i];
	vector<int> sub(n+1);
	rep(i, n) sub[i+1] += sub[i] + (b[i] == 0 ? 1 : -1);
	cin >> q;
	vector<int> l(q), r(q);
	rep(i, q) cin >> l[i] >> r[i];
	vector<int> ord(q);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return l[li] < l[ri]; });
	segtree<int, op, e> st0(n+1), st1(n+1);
	int sval = count(all(b), 1);
	st0.set(0, sval), st1.set(0, sval);
	rep(i, q) {
		st0.set(r[ord[i]], st0.prod(0, l[ord[i]]) + (sub[r[ord[i]]]-sub[l[ord[i]]-1]));
		st1.set(r[ord[i]], min(st1.get(r[ord[i]]), st0.get(r[ord[i]])-sub[r[ord[i]]]));
		st0.set(r[ord[i]], min(st0.get(r[ord[i]]), st1.prod(l[ord[i]], r[ord[i]]+1) + sub[r[ord[i]]]));
		st1.set(r[ord[i]], min(st1.get(r[ord[i]]), st0.get(r[ord[i]])-sub[r[ord[i]]]));
	}
	cout << st0.all_prod() << endl;
	return 0;
}
