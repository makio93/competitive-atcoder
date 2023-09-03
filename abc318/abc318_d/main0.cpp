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
	int n;
	cin >> n;
	vector<vector<int>> d(n, vector<int>(n));
	rep(i, n-1) rep3(j, i+1, n) {
		int di;
		cin >> di;
		d[i][j] = d[j][i] = di;
	}
	ll res = 0;
	vector<bool> check(n);
	function<void(int, ll)> dfs = [&](int di, ll val) {
		if (di == n/2) {
			res = max(res, val);
			return;
		}
		int vi = 0;
		while (check[vi]) ++vi;
		check[vi] = true;
		rep3(ti, vi+1, n) if (!check[ti]) {
			check[ti] = true;
			dfs(di+1, val+d[vi][ti]);
			check[ti] = false;
		}
		check[vi] = false;
	};
	if (n%2 == 0) dfs(0, 0LL);
	else {
		rep(i, n) {
			check[i] = true;
			dfs(0, 0LL);
			check[i] = false;
		}
	}
	cout << res << endl;
	return 0;
}
