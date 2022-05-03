// 自力AC1

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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	auto dfs = [&](auto dfs, int v=0, int d=0) -> ll {
		if (v == n) return (d == k) ? 0 : LINF;
		ll res = dfs(dfs, v+1, d);
		if (d < k) {
			ll val = 0;
			int mval = 0;
			rep(i, v) mval = max(mval, a[i]);
			int sub = max(0, mval+1-a[v]);
			a[v] += sub;
			val += sub;
			val += dfs(dfs, v+1, d+1);
			a[v] -= sub;
			res = min(res, val);
		}
		return res;
	};
	cout << dfs(dfs) << endl;
	return 0;
}
