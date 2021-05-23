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

vector<vector<int>> g, dl;
vector<int> in, out, dep;
int times;

void dfs(int v) {
	in[v] = times; ++times;
	dl[dep[v]].push_back(in[v]);
	for (auto t : g[v]) {
		dep[t] = dep[v] + 1;
		dfs(t);
	}
	out[v] = times; ++times;
}

int main() {
	int n, q;
	cin >> n;
	g = dl = vector<vector<int>>(n);
	in = out = dep = vector<int>(n, -1);
	rep3(i, 1, n) {
		int pi;
		cin >> pi;
		--pi;
		g[pi].push_back(i);
	}
	dep[0] = 0;
	dfs(0);
	cin >> q;
	rep(i, q) {
		int ui, di;
		cin >> ui >> di;
		--ui;
		int res = lower_bound(all(dl[di]), out[ui]) - lower_bound(all(dl[di]), in[ui]);
		cout << res << endl;
	}
	return 0;
}
