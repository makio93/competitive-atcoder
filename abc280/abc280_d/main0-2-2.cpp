// 本番WA2-2

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

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }

int main() {
	ll k;
	cin >> k;
	ll kval = k, res = 1;
	for (ll i=2; i*i<=k; ++i) {
		if (kval == 1) break;
		ll gval = gcd(kval, i);
		if (gval == 1) continue;
		kval /= gval;
		res = max(res, i);
	}
	if (kval > 1) res = max(res, (res+kval-1)/kval*kval);
	cout << res << endl;
	return 0;
}
