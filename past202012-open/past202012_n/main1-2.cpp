// 解説AC2

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

const int INF = (int)(2e9);
int op0(int ai, int bi) { return max(ai, bi); }
int e0() { return -1; }
int op1(int ai, int bi) { return min(ai, bi); }
int e1() { return INF; }

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> l(n-1), r(n-1), a(q), b(q);
	rep(i, n-1) cin >> l[i] >> r[i];
	rep(i, q) {
		cin >> a[i] >> b[i];
		b[i]--;
	}
	segtree<int, op0, e0> st0(n-1);
	segtree<int, op1, e1> st1(n-1);
	rep(i, n-1) st0.set(i, l[i]);
	rep(i, n-1) st1.set(i, r[i]);
	vector<int> res(q);
	rep(i, q) {
		int li = b[i], ri = n;
		while (ri-li > 1) {
			int ci = li + (ri-li) / 2;
			if (st0.prod(b[i], ci) <= a[i] && st1.prod(b[i], ci) >= a[i]) li = ci;
			else ri = ci;
		}
		res[i] = li - b[i] + 1;
		li = -1, ri = b[i];
		while (ri-li > 1) {
			int ci = ri - (ri-li) / 2;
			if (st0.prod(ci, b[i]) <= a[i] && st1.prod(ci, b[i]) >= a[i]) ri = ci;
			else li = ci;
		}
		res[i] += b[i] - ri;
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
