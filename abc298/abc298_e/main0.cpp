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

int main() {
	int n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	--a; --b;
	vector<vector<vector<bool>>> exists(n, vector<vector<bool>>(n, vector<bool>(2)));
	vector<vector<vector<mint>>> memo(n, vector<vector<mint>>(n, vector<mint>(2)));
	function<mint(int,int,int)> calc = [&](int ai, int bi, int ti) {
		if (exists[ai][bi][ti]) return memo[ai][bi][ti];
		exists[ai][bi][ti] = true;
		if (ai == n-1) return memo[ai][bi][ti] = 1;
		if (bi == n-1) return memo[ai][bi][ti] = 0;
		mint rval = 0;
		if (ti == 0) {
			rep3(i, 1, p+1) {
				if (ai+i > n-1) rval += 1;
				else rval += calc(ai+i, bi, 1-ti);
			}
			rval /= p;
		}
		else {
			rep3(i, 1, q+1) {
				if (bi+i <= n-1) rval += calc(ai, bi+i, 1-ti);
			}
			rval /= q;
		}
		return memo[ai][bi][ti] = rval;
	};
	mint res = calc(a, b, 0);
	cout << res.val() << endl;
	return 0;
}
