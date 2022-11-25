// 学習1,解説AC3

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
int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
	int q;
	cin >> q;
	vector<int> qi(q), ki(q, -1);
	vector<ll> xi(q);
	rep(i, q) {
		cin >> qi[i] >> xi[i];
		if (qi[i] != 1) cin >> ki[i];
	}
	vector<ll> txi = xi;
	sort(all(txi));
	txi.erase(unique(all(txi)), txi.end());
	rep(i, q) xi[i] = lower_bound(all(txi), xi[i]) - txi.begin();
	int m = txi.size();
	segtree<int, op, e> st(m);
	rep(i, q) {
		if (qi[i] == 1) st.set(xi[i], st.get(xi[i])+1);
		else if (qi[i] == 2) {
			int li = st.min_left<function<bool(int)>>(xi[i]+1, [&](int a) -> bool {
				return a < ki[i];
			});
			if (li-1 >= 0) cout << txi[li-1] << endl;
			else cout << -1 << endl;
		}
		else {
			int ri = st.max_right<function<bool(int)>>(xi[i], [&](int a) -> bool {
				return a < ki[i];
			});
			if (ri < m) cout << txi[ri] << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}
