// 解説AC

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
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> p(n, -1), deg(n);
	rep(i, n) deg[i] = g[i].size();
	queue<int> que;
	rep(i, n) if (deg[i] == 1) que.push(i);
	while ((int)(que.size()) >= 2) {
		int ui = que.front(); que.pop();
		int vi = que.front(); que.pop();
		p[ui] = vi;
		p[vi] = ui;
		for (const int& ti : g[ui]) {
			deg[ti]--;
			if (deg[ti] == 1) que.push(ti);
		}
		for (const int& ti : g[vi]) {
			deg[ti]--;
			if (deg[ti] == 1) que.push(ti);
		}
	}
	if (!que.empty()) p[que.front()] = que.front();
	rep(i, n) cout << (p[i]+1) << (i<n-1?' ':'\n');
	return 0;
}
