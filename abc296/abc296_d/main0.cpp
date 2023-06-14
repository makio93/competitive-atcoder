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

int main() {
	ll n, m;
	cin >> n >> m;
	ll res = LINF;
	for (ll a=1; (a-1)*(a-1)<m; ++a) {
		ll b = (m+a-1) / a;
		if (a>n || b>n) continue;
		res = min(res, a*b);
	}
	if (res == LINF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
