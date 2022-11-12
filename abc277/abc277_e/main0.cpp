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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ui, vi, ai;
		cin >> ui >> vi >> ai;
		--ui; --vi;
		g[ui].emplace_back(vi, ai);
		g[vi].emplace_back(ui, ai);
	}
	unordered_set<int> s;
	rep(i, k) {
		int si;
		cin >> si;
		--si;
		s.insert(si);
	}
	vector<vector<int>> dist(n, vector<int>(2, INF));
	deque<pair<int, int>> deq;
	dist[0][0] = 0;
	deq.emplace_back(0, 0);
	while (!deq.empty()) {
		auto pi = deq.front(); deq.pop_front();
		int vi = pi.first, si = pi.second, di = dist[vi][si];
		if (s.find(vi) != s.end()) {
			int nsi = 1 - si;
			if (dist[vi][nsi] > di) {
				dist[vi][nsi] = di;
				deq.emplace_front(vi, nsi);
			}
		}
		for (const auto& tpi : g[vi]) if (tpi.second == 1-si) {
			int ti = tpi.first, ndi = di + 1;
			if (dist[ti][si] > ndi) {
				dist[ti][si] = ndi;
				deq.emplace_back(ti, si);
			}
		}
	}
	int res = min(dist[n-1][0], dist[n-1][1]);
	if (res == INF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
