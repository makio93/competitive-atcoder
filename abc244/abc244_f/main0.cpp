// 本番AC

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
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<vector<int>> dist(n, vector<int>(1<<n, INF));
	rep(i, n) {
		queue<pair<int, int>> que;
		que.emplace(i, (1<<i));
		dist[i][1<<i] = 1;
		while (!que.empty()) {
			int vi = que.front().first, si = que.front().second; que.pop();
			int di = dist[vi][si], ndi = di + 1;
			for (int ti : g[vi]) {
				int nsi = si ^ (1<<ti);
				if (dist[ti][nsi] <= ndi) continue;
				dist[ti][nsi] = ndi;
				que.emplace(ti, nsi);
			}
		}
	}
	int res = 0;
	rep3(i, 1, (1<<n)) {
		int val = INF;
		rep(j, n) val = min(val, dist[j][i]);
		res += val;
	}
	cout << res << endl;
	return 0;
}
