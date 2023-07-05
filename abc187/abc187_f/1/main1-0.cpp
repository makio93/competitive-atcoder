// 学習1回目,バチャ解説AC-0

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
	int n, m;
	cin >> n >> m;
	vector<int> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai] |= 1 << bi;
		g[bi] |= 1 << ai;
	}
	if (m == 0) {
		cout << n << endl;
		return 0;
	}
	rep(i, n) g[i] |= 1 << i;
	vector<int> memo(1<<n, -1);
	function<int(int)> dp = [&](int vi) {
		if (memo[vi] != -1) return memo[vi];
		if (vi == 0) return memo[vi] = 0;
		if (__builtin_popcount(vi) == 1) memo[vi] = 1;
		bool ok = true;
		rep(i, n) if ((vi>>i&1) && (g[i]&vi)!=vi) ok = false;
		if (ok) return memo[vi] = 1;
		int rval = __builtin_popcount(vi);
		for (int i=vi; i>0; i=(i-1)&vi) {
			if (i == vi) continue;
			int t1 = i, t2 = vi ^ i;
			if (t2 < t1) continue;
			rval = min(rval, dp(t1)+dp(t2));
		}
		return memo[vi] = rval;
	};
	int res = dp((1<<n)-1);
	cout << res << endl;
	return 0;
}
