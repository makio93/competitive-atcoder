// 学習1回目,解説AC

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

using mint = modint998244353;

mint sigma(ll val) {
	return mint(1 + val) * val / 2;
}

int main() {
	ll n;
	cin >> n;
	mint res = 0;
	ll ten = 1;
	rep(i, 18) {
		ll lval = ten, rval = min(n, ten*10-1);
		if (n < lval) break;
		res += sigma(rval-lval+1);
		ten *= 10;
	}
	cout << res.val() << endl;
	return 0;
}
