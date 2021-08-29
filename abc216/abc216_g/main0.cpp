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

// 自力WA

pair<int, int> op1(pair<int, int> a, pair<int, int> b) { return max(a, b); }
pair<int, int> e1() { return { 0, -1 }; }

int op2(int a, int b) { return (a + b); }
int e2() { return 0; }

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m), x(m);
	rep(i, m) {
		cin >> l[i] >> r[i] >> x[i];
		l[i]--;
	}
	vector<int> sub1(n+1);
	rep(i, m) {
		sub1[l[i]]++;
		sub1[r[i]]--;
	}
	rep(i, n) sub1[i+1] += sub1[i];
	segtree<pair<int, int>, op1, e1> seg1(n+1);
	rep(i, n+1) seg1.set(i, { sub1[i], i });
	segtree<int, op2, e2> seg2(n+1);
	rep(i, m) {
		int vsum = seg2.prod(l[i], r[i]);
		while (vsum < x[i]) {
			auto [mi, pi] = seg1.prod(l[i], r[i]);
			seg1.set(pi, { -1, pi });
			seg2.set(pi, 1);
			vsum = seg2.prod(l[i], r[i]);
		}
	}
	vector<int> res(n);
	rep(i, n) res[i] = min(1, seg2.get(i));
	rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
