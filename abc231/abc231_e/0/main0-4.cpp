// 本番終了後,自力考察,解けない

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int n;
ll calc(vector<ll>& a, ll x) {
	ll res = 0;
	repr(i, n) if (a[i] <= x) {
		res += x / a[i];
		x = x % a[i];
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
		ll mval = x / a[i] * a[i];
		res = min(res, calc(a, mval)+calc(a, x-mval));
		res = min(res, calc(a, mval+a[i])+calc(a, mval+a[i]-x));
	}
	cout << res << endl;
	return 0;
}
