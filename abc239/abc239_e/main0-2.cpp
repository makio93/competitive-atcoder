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
	int n, q;
	cin >> n >> q;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<vector<int>> ranks(n);
	function<vector<int>(int, int)> dfs = [&](int vi, int pi) -> vector<int> {
		vector<int> rlst;
		rlst.push_back(x[vi]);
		for (int ti : g[vi]) if (ti != pi) {
			auto tlst = dfs(ti, vi);
			for (int tval : tlst) rlst.push_back(tval);
		}
		sort(rlst.rbegin(), rlst.rend());
		vector<int> res;
		int m = rlst.size();
		for (int i=0; i<min(m,20); ++i) res.push_back(rlst[i]);
		ranks[vi] = res;
		return res;
	};
	dfs(0, -1);
	rep(i, q) {
		int vi, ki;
		cin >> vi >> ki;
		--vi; --ki;
		cout << ranks[vi][ki] << endl;
	}
	return 0;
}
