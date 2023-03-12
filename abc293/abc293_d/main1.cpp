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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> deg(n);
	rep(i, m) {
		int ai, ci;
		char bi, di;
		cin >> ai >> bi >> ci >> di;
		--ai; --ci;
		g[ai].push_back(ci);
		g[ci].push_back(ai);
		deg[ai]++; deg[ci]++;
	}
	vector<bool> visited(n);
	int x = 0, y = 0;
	rep(i, n) if (!visited[i]) {
		queue<int> que;
		que.push(i);
		visited[i] = true;
		bool roop = true;
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			if (deg[vi] != 2) roop = false;
			for (const int& ti : g[vi]) if (!visited[ti]) {
				que.push(ti);
				visited[ti] = true;
			}
		}
		if (roop) ++x;
		else ++y;
	}
	cout << x << ' ' << y << endl;
	return 0;
}
