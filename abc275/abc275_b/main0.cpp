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

const ll mod = 998244353LL;

int main() {
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	ll val1 = (a % mod) * (b % mod) % mod * (c % mod) % mod, val2 = (d % mod) * (e % mod) % mod * (f % mod) % mod;
	ll res = (val1 - val2 + mod) % mod;
	cout << res << endl;
	return 0;
}
