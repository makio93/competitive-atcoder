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
	rep3(i, 1, n) {
		int pi;
		cin >> pi;
		--pi;
		g[pi].push_back(i);
	}
	vector<int> dists(n, -1);
	priority_queue<pair<int, int>> pq;
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi;
		if (dists[xi] >= yi) continue;
		dists[xi] = yi;
		pq.emplace(yi, xi);
	}
	while (!pq.empty()) {
		auto [di, vi] = pq.top(); pq.pop();
		if (dists[vi] != di) continue;
		int ndi = di - 1;
		for (const int& ti : g[vi]) {
			if (dists[ti] >= ndi) continue;
			dists[ti] = ndi;
			pq.emplace(ndi, ti);
		}
	}
	int res = 0;
	rep(i, n) if (dists[i] >= 0) ++res;
	cout << res << endl;
	return 0;
}
