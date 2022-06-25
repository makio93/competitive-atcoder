// 本番終了後,自力AC

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
	vector<vector<int>> g(n+1);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> dist(n+1, INF), dist1(n+1, INF), distn(n+1, INF);
	auto bfs = [&](vector<int>& dt, int si) -> void {
		queue<int> que;
		dt[si] = 0;
		que.push(si);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dt[vi], ndi = di + 1;
			for (int ti : g[vi]) if (dt[ti] == INF) {
				dt[ti] = ndi;
				que.push(ti); 
			}
		}
	};
	bfs(dist, 1);
	bfs(dist1, 1);
	bfs(distn, n);
	rep3(i, 1, n+1) {
		int res = dist[n];
		res = min(res, min(dist1[i], dist1[0]) + min(distn[i], distn[0]));
		if (res == INF) cout << -1;
		else cout << res;
		cout << (i<n?' ':'\n');
	}
	return 0;
}
