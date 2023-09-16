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
	vector<vector<pair<int, pair<int, int>>>> g(n);
	rep(i, m) {
		int ai, bi, xi, yi;
		cin >> ai >> bi >> xi >> yi;
		--ai; --bi;
		g[ai].emplace_back(bi, make_pair(xi, yi));
		g[bi].emplace_back(ai, make_pair(-xi, -yi));
	}
	vector<pair<ll, ll>> dist(n);
	vector<int> status(n);
	queue<int> que;
	status[0] = 1;
	dist[0] = { 0, 0 };
	que.push(0);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		auto [xi, yi] = dist[vi];
		for (const auto [ti, tdi] : g[vi]) {
			if (status[ti] == -1) continue;
			const auto [tdxi, tdyi] = tdi;
			ll txi = xi + tdxi, tyi = yi + tdyi;
			if (status[ti] == 1) {
				if (dist[ti].first == txi && dist[ti].second == tyi) continue;
				status[ti] = -1;
				continue;
			}
			status[ti] = 1;
			dist[ti] = { txi, tyi };
			que.push(ti);
		}
	}
	rep(i, n) {
		if (status[i] == 1) cout << dist[i].first << ' ' << dist[i].second << endl;
		else cout << "undecidable" << endl;
	}
	return 0;
}
