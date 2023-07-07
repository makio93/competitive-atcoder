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
	vector<int> ord(m);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return r[li] < r[ri]; });
	segtree<ll, op, e> st1(n+1), st2(n+1);
	st1.set(0, 0LL);
	st2.set(0, 0LL);
	rep(i, m) {
		st1.set(r[ord[i]], max(st1.get(r[ord[i]]), st1.prod(0, l[ord[i]]) + (s[r[ord[i]]]-s[l[ord[i]]]) - c[ord[i]]));
		st1.set(r[ord[i]], max(st1.get(r[ord[i]]), st2.prod(l[ord[i]], r[ord[i]]) + s[r[ord[i]]] - c[ord[i]]));
		st2.set(r[ord[i]], max(st2.get(r[ord[i]]), st1.get(r[ord[i]]) - s[r[ord[i]]]));
	}
	ll res = st1.all_prod();
	cout << res << endl;
	return 0;
}
