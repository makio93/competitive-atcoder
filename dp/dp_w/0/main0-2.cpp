// 自力WA2

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

const ll LINF = (ll)(1e18);
ll op(ll a, ll b) { return max(a, b); }
ll e() { return -LINF; }

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m), a(m);
	rep(i, m) cin >> l[i] >> r[i] >> a[i];
	vector<int> ord(m);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return make_pair(l[li], r[li]) < make_pair(l[ri], r[ri]); });
	segtree<ll, op, e> st(n+1);
	st.set(0, 0);
	int mi = 0;
	ll res = 0;
	rep(i, n) {
		ll nv = st.prod(0, i+1);
		while (mi<m && l[mi]==i+1) {
			nv += a[mi];
			st.set(r[mi], max(st.get(r[mi]), st.get(i)));
			res = max(res, st.get(r[mi]));
			++mi;
		}
		st.set(i+1, max(st.get(i+1), nv));
	}
	cout << max(st.all_prod(), res) << endl;
	return 0;
}
