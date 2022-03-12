// 本番1TLE

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

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<ll> c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	vector<pair<ll, int>> clst(m);
	rep(i, m) clst[i] = { c[i], i };
	sort(all(clst));
	dsu ds(n);
	vector<set<pair<int, ll>>> g(n);
	int res = 0;
	rep(i, m) {
		int ai = a[clst[i].second], bi = b[clst[i].second];
		ll ci = clst[i].first;
		if (!ds.same(ai, bi)) {
			ds.merge(ai, bi);
			g[ai].emplace(bi, ci);
			g[bi].emplace(ai, ci);
		}
		else {
			const ll INF = (ll)(1e17);
			vector<ll> dist(n, INF);
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
			dist[ai] = 0;
			pq.emplace(0, ai);
			while (!pq.empty()) {
				auto pi = pq.top(); pq.pop();
				ll di = pi.first;
				int vi = pi.second;
				if (dist[vi] != di) continue;
				for (auto tpi : g[vi]) {
					int ti = tpi.first;
					ll ndi = di + tpi.second;
					if (dist[ti] <= ndi) continue;
					dist[ti] = ndi;
					pq.emplace(ndi, ti);
				}
			}
			if (dist[bi] <= ci) ++res;
			else {
				g[ai].emplace(bi, ci);
				g[bi].emplace(ai, ci);
			}
		}
	}
	cout << res << endl;
	return 0;
}
