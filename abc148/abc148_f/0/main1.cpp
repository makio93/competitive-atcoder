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
	int n, u, v;
	cin >> n >> u >> v;
	--u; --v;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> vdist(n, INF), udist(n, INF);
	queue<int> que;
	que.push(v);
	vdist[v] = 0;
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = vdist[vi], ndi = di + 1;
		for (int ti : g[vi]) if (vdist[ti] == INF) {
			que.push(ti);
			vdist[ti] = ndi;
		}
	}
	int res = 0;
	que.push(u);
	udist[u] = 0;
	if ((int)(g[u].size())==1 && udist[u]<vdist[u]) res = max(res, vdist[u]-1);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = udist[vi], ndi = di + 1;
		for (int ti : g[vi]) if (udist[ti] == INF) {
			que.push(ti);
			udist[ti] = ndi;
			if ((int)(g[ti].size())==1 && udist[ti]<vdist[ti]) res = max(res, vdist[ti]-1);
		}
	}
	cout << res << endl;
	return 0;
}
