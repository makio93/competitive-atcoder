// 本番AC

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

int main() {
	int n;
	ll l, w;
	cin >> n >> l >> w;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<pair<ll, ll>> b;
	b.emplace_back(0, 0);
	rep(i, n) b.emplace_back(a[i]+w, a[i]);
	b.emplace_back(l, l);
	sort(all(b));
	ll res = 0;
	rep(i, n+1) {
		ll sub = max(0LL, b[i+1].second-b[i].first);
		res += (sub+w-1) / w;
	}
	cout << res << endl;
	return 0;
}
