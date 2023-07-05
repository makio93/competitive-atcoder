// 学習1回目,バチャ本番,TLE

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
		vector<int> vlst;
		rep(i, n) if (vi>>i&1) vlst.push_back(i);
		int vlen = vlst.size(), rval = vlen;
		vlst.reserve(n);
		rep3(i, 1, (1<<vlen)-1) {
			int t1 = 0, t2 = 0;
			rep(j, vlen) {
				if (i>>j&1) t1 |= 1 << vlst[j];
				else t2 |= 1 << vlst[j];
			}
			if (t2 < t1) continue;
			rval = min(rval, dp(t1)+dp(t2));
		}
		return memo[vi] = rval;
	};
	int res = dp((1<<n)-1);
	cout << res << endl;
	return 0;
}
