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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<bool> visited(n);
	function<bool(int, int)> dfs = [&](int vi, int pi) {
		visited[vi] = true;
		int k;
		cin >> k;
		rep(i, k) {
			int ti;
			cin >> ti;
			--ti;
			g[vi].push_back(ti);
		}
		rep(i, k) if (!visited[g[vi][i]]) {
			cout << (g[vi][i]+1) << endl;
			cout.flush();
			if (g[vi][i] == n-1) {
				string s;
				cin >> s;
				return true;
			}
			if (dfs(g[vi][i], vi)) return true;
		}
		cout << (pi+1) << endl;
		cout.flush();
		int tk;
		cin >> tk;
		rep(i, tk) {
			int ti;
			cin >> ti;
		}
		return false;
	};
	dfs(0, -1);
	return 0;
}
