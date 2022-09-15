// 自力AC

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
	int n, x;
	cin >> n >> x;
	--x;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	auto dfs = [&](auto dfs, int vi, int pi=-1) -> pair<bool, int> {
		bool exist = (h[vi] == 1);
		int res = 0;
		for (int& ti : g[vi]) if (ti != pi) {
			auto tpi = dfs(dfs, ti, vi);
			if (tpi.first) {
				res += tpi.second + 2;
				exist = true;
			}
		}
		return { exist, res };
	};
	auto rval = dfs(dfs, x);
	cout << rval.second << endl;
	return 0;
}
