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
	ll k;
	cin >> n >> k;
	vector<pair<ll, ll>> ab(n);
	rep(i, n) cin >> ab[i].first >> ab[i].second;
	sort(all(ab));
	vector<ll> a(n), b(n);
	rep(i, n) {
		a[i] = ab[i].first;
		b[i] = ab[i].second;
	}
	ll v = 0;
	rep(i, n) {
		ll dist = a[i] - v;
		ll move = min(k, dist);
		v += move;
		k -= move;
		if (v < a[i]) break;
		k += b[i];
	}
	if (k > 0LL) v += k;
	cout << v << endl;
	return 0;
}
