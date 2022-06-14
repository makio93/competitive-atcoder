// 本番WA2

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

const ll INF = (ll)(1.5e18);

int n;
ll calc(vector<ll>& a, ll x) {
	ll res = 0;
	repr(i, n) if (a[i] <= x) {
		res += x / a[i];
		x -= x / a[i] * a[i];
	}
	return res;
}

int main() {
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll res = calc(a, x);
	repr(i, n) {
		ll mval = x / a[i] * a[i] + a[i];
		res = min(res, calc(a, mval)+calc(a, mval-x));
	}
	cout << res << endl;
	return 0;
}
