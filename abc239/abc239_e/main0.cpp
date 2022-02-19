// 本番提出,WA

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
	vector<int> v(q), k(q);
	vector<vector<int>> vtoq(n);
	rep(i, q) {
		cin >> v[i] >> k[i];
		v[i]--; k[i]--;
		vtoq[v[i]].push_back(i);
	}
	vector<int> res(q);
	function<pair<int, multiset<int>>&(int, int)> dfs = [&](int vi, int pi) -> pair<int, multiset<int>>& {
		vector<pair<int, multiset<int>>> rlst;
		rlst.emplace_back(1, multiset<int>({ x[vi] }));
		for (int ti : g[vi]) if (ti != pi) rlst.push_back(dfs(ti, vi));
		sort(rlst.rbegin(), rlst.rend());
		int m = rlst.size();
		rep3r(i, 1, m) {
			rlst[0].first += rlst[i].first;
			for (int ri : rlst[i].second) rlst[0].second.insert(ri);
		}
		int len = vtoq[vi].size();
		rep(i, len) {
			int ki = k[vtoq[vi][i]], kcnt = 0;
			auto itr = rlst[0].second.rbegin();
			while (kcnt < ki) {
				++itr;
				++kcnt;
			}
			res[vtoq[vi][i]] = *itr;
		}
		return rlst[0];
	};
	dfs(0, -1);
	rep(i, q) cout << res[i] << endl;
	return 0;
}
