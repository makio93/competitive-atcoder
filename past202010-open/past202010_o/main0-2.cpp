// 自力AC2

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
	vector<int> a(n), l(m), r(m), c(m);
	rep(i, n) cin >> a[i];
	rep(i, m) {
		cin >> l[i] >> r[i] >> c[i];
		l[i]--;
	}
	vector<ll> s(n+1);
	rep(i, n) s[i+1] += s[i] + a[i];
	vector<vector<int>> rids(n+1);
	rep(i, m) rids[r[i]].push_back(i);
	segtree<ll, op, e> st1(n+1), st2(n+1);
	st1.set(0, 0LL);
	st2.set(0, 0LL);
	rep3(i, 1, n+1) {
		st1.set(i, st1.get(i-1));
		st2.set(i, st1.get(i) - s[i]);
		for (const int& id : rids[i]) {
			st1.set(r[id], max(st1.get(r[id]), st1.prod(0, l[id]) + (s[r[id]]-s[l[id]]) - c[id]));
			st1.set(r[id], max(st1.get(r[id]), st2.prod(l[id], r[id]) + s[r[id]] - c[id]));
			st2.set(r[id], max(st2.get(r[id]), st1.get(r[id]) - s[r[id]]));
		}
	}
	ll res = st1.all_prod();
	cout << res << endl;
	return 0;
}
