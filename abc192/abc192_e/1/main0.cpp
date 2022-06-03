// バチャ参加,自力AC

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

const ll LINF = (ll)(1e18);

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	--x; --y;
	vector<vector<pair<int, int>>> g(n);
	vector<int> t(m), k(m);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi >> t[i] >> k[i];
		--ai; --bi;
		g[ai].emplace_back(bi, i);
		g[bi].emplace_back(ai, i);
	}
	vector<ll> dist(n, LINF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[x] = 0;
	pq.emplace(0, x);
	while (!pq.empty()) {
		auto vpi = pq.top(); pq.pop();
		ll di = vpi.first; int vi = vpi.second;
		if (dist[vi] != di) continue;
		for (auto tpi : g[vi]) {
			int ti = tpi.first, mid = tpi.second;
			ll ndi = (di+k[mid]-1) / k[mid] * k[mid] + t[mid];
			if (dist[ti] <= ndi) continue;
			dist[ti] = ndi;
			pq.emplace(ndi, ti);
		}
	}
	if (dist[y] == LINF) cout << -1 << endl;
	else cout << dist[y] << endl;
	return 0;
}
