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

int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> l(n), r(n);
	function<int(int,int,int)> dfs = [&](int vi, int pi, int val) -> int {
		l[vi] = val;
		bool ch = false;
		for (int ti : g[vi]) if (ti != pi) {
			if (!ch) ch = true;
			else ++val;
			val = dfs(ti, vi, val);
		}
		r[vi] = val;
		return val;
	};
	dfs(0, -1, 1);
	rep(i, n) cout << l[i] << ' ' << r[i] << endl;
	return 0;
}
