#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番WA1

const ll mod = 998244353LL;

int main() {
	ll n;
	cin >> n;
	ll res = 0;
	for (ll x=1; x<=min(n,(ll)(2e6)); ++x) {
		ll h1 = x * x - 1, h2 = max(-1LL, x*x-n-1);
		ll r1 = (ll)round(sqrtl(h1));
		if (h2 == -1LL) res = (res + r1) % mod;
		else {
			ll r2 = (ll)round(sqrtl(h2));
			res = (res + r1 - r2) % mod;
		}
	}
	cout << res << endl;
	return 0;
}
