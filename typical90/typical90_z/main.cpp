#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

vector<int> depth;
void dfs(vector<vector<int>>& g, int v, int p=-1, int d=0) {
	depth[v] = d;
	rep(i, (int)(g[v].size())) {
		int t = g[v][i];
		if (t == p) continue;
		dfs(g, t, v, d+1);
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	depth = vector<int>(n, -1);
	dfs(g, 0);
	vector<vector<int>> vlst(2);
	rep(i, n) vlst[depth[i]%2].push_back(i+1);
	int lid = (vlst[0].size() >= vlst[1].size()) ? 0 : 1, len = n / 2;
	rep(i, len) printf("%d%c", vlst[lid][i], (i<len-1?' ':'\n'));
	return 0;
}
