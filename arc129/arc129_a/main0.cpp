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

// 本番AC

int main() {
	ll n, l, r;
	cin >> n >> l >> r;
	ll res = 0;
	repr(i, 60) {
		if ((1LL<<i) > r) continue;
		if ((1LL<<(i+1))-1 < l) continue;
		if (!((n>>i)&1LL)) continue;
		ll rval = min(r, (1LL<<(i+1))-1), lval = max(l, (1LL<<i));
		res += rval - lval + 1;
	}
	cout << res << endl;
	return 0;
}
