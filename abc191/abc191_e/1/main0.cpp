// 学習1回目,自力AC

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
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		--ai; --bi;
		g[ai].emplace_back(bi, ci);
	}
	vector<int> dist;
	rep(i, n) {
		dist.assign(n, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (auto& pti : g[i]) if (dist[pti.first] > pti.second) {
			dist[pti.first] = pti.second;
			pq.emplace(pti.second, pti.first);
		}
		while (!pq.empty()) {
			auto pi = pq.top(); pq.pop();
			int di = pi.first, vi = pi.second;
			if (dist[vi] != di) continue;
			for (auto& pti : g[vi]) if (dist[pti.first] > di+pti.second) {
				dist[pti.first] = di+pti.second;
				pq.emplace(di+pti.second, pti.first);
			}
		}
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}
