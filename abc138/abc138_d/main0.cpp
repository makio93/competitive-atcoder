// 

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
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> vals(n);
	rep(i, q) {
		int pi, xi;
		cin >> pi >> xi;
		--pi;
		vals[pi] += xi;
	}
	auto dfs = [&](auto dfs, int vi=0, int pi=-1, int add=0) -> void {
		vals[vi] += add;
		for (int ti : g[vi]) if (ti != pi) dfs(dfs, ti, vi, vals[vi]);
	};
	dfs(dfs);
	rep(i, n) cout << vals[i] << (i<n-1?' ':'\n');
	return 0;
}
