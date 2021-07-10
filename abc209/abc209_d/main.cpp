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

int n;
vector<int> dep;
vector<vector<int>> g;
void dfs(int d=0, int v=0, int p=-1) {
	dep[v] = d;
	for (int t : g[v]) if (t != p) dfs(d+1, t, v);
}

int main() {
	int q;
	cin >> n >> q;
	g = vector<vector<int>>(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	dep = vector<int>(n, -1);
	dfs();
	rep(i, q) {
		int ci, di;
		cin >> ci >> di;
		--ci; --di;
		int dval = dep[ci] + dep[di];
		if (dval%2 == 0) cout << "Town" << endl;
		else cout << "Road" << endl;
	}
	return 0;
}
