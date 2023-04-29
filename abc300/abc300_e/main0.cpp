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

using mint = modint998244353;
const ll mod = 998244353LL;

int main() {
	ll n;
	cin >> n;
	unordered_map<ll, mint> memo;
	auto f = [&](auto& f, ll val) -> mint {
		if (memo.find(val) != memo.end()) return memo[val];
		if (val == 1) return memo[val] = 1;
		mint rval = 0;
		rep3(i, 2, 7) {
			if (val%i != 0) continue;
			rval += f(f, val/i) / 6;
		}
		rval += rval / 5;
		return memo[val] = rval;
	};
	mint res = f(f, n);
	cout << res.val() << endl;
	return 0;
}
