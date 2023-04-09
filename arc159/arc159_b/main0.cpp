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

const ll LINF = (ll)(1e18);

ll mygcd(ll a, ll b) { return (b ? mygcd(b, a%b) : a); }

int main() {
	ll a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);
	ll tg = mygcd(a, b);
	a /= tg; b /= tg;
	ll res = 0;
	while (a>1 && b>1) {
		ll s = b - a;
		pair<ll, ll> mval = { a, 1 };
		for (ll i=2; i*i<=s; ++i) if (s%i == 0) {
			mval = min(mval, { a%i, i });
			while (s%i == 0) s /= i;
		}
		if (s > 1) mval = min(mval, { a%s, s });
		res += mval.first;
		a -= mval.first; b -= mval.first;
		a /= mval.second; b /= mval.second;
	}
	if (a>0 && b>0) res += min(a, b);
	cout << res << endl;
	return 0;
}
