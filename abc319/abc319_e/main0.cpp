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

const int INF = (int)(1e9);

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> p(n-1), t(n-1);
	rep(i, n-1) cin >> p[i] >> t[i];
	map<tuple<int, int, int, int, int, int, int, int>, ll> memo;
	function<ll(int)> f = [&](int si) {
		if (memo.find({si%1, si%2, si%3, si%4, si%5, si%6, si%7, si%8}) != memo.end()) return (ll)(si) + memo[{si%1, si%2, si%3, si%4, si%5, si%6, si%7, si%8}];
		ll rval = si + (ll)x;
		rep(i, n-1) {
			int tmp = (p[i] - rval % p[i]) % p[i];
			rval += tmp + t[i];
		}
		rval += y;
		memo[{si%1, si%2, si%3, si%4, si%5, si%6, si%7, si%8}] = rval - si;
		return rval;
	};
	int q;
	cin >> q;
	rep(i, q) {
		int qi;
		cin >> qi;
		ll res = f(qi);
		cout << res << endl;
	}
	return 0;
}
