// 自力WA

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
	int n;
	cin >> n;
	vector<int> a(n+1), b(n+1);
	rep3(i, 1, n+1) cin >> a[i] >> b[i];
	vector<int> ids, s(n+1);
	ids.push_back(0);
	rep3(i, 1, n+1) if (b[i] > b[ids.back()]) ids.push_back(i);
	ids.push_back(n+1);
	rep(i, n) s[i+1] = s[i] + a[i+1];
	int m = ids.size() - 1;
	segtree<ll, op, e> st(m);
	st.set(0, 0LL);
	rep3(i, 1, m) {
		ll tval = st.prod(0, i) + s[ids[i]] - b[ids[i]];
		if (tval < 0) continue;
		st.set(i, max(st.get(i), st.prod(0, i) - b[ids[i]]));
	}
	if (st.get(m-1) == -LINF) cout << -1 << endl;
	else cout << (st.get(m-1)+s[ids[m]-1]) << endl;
	return 0;
}
