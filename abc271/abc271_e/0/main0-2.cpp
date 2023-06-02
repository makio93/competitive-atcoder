// 自力AC

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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	vector<int> e(k);
	rep(i, k) {
		cin >> e[i];
		e[i]--;
	}
	vector<set<int>> eids(m);
	rep(i, k) eids[e[i]].insert(i);
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		if (eids[i].empty()) continue;
		g[a[i]].emplace_back(i, c[i]);
	}
	vector<map<int, ll>> dist(n);
	priority_queue<pair<pair<int, ll>, int>, vector<pair<pair<int, ll>, int>>, greater<pair<pair<int, ll>, int>>> pq;
	pq.emplace(make_pair(-1, 0), 0);
	dist[0][-1] = 0;
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int ki = pi.first.first, vi = pi.second;
		ll di = pi.first.second;
		if (dist[vi].find(ki)==dist[vi].end() || dist[vi][ki]!=di) continue;
		for (auto tpi : g[vi]) {
			auto itr = eids[tpi.first].upper_bound(ki);
			if (itr == eids[tpi.first].end()) continue;
			int tki = *itr;
			ll ndi = di + tpi.second;
			if (dist[b[tpi.first]].find(tki)!=dist[b[tpi.first]].end() && dist[b[tpi.first]][tki]<=ndi) continue;
			auto titr = dist[b[tpi.first]].upper_bound(tki);
			while (titr!=dist[b[tpi.first]].end() && titr->second>=ndi) titr = dist[b[tpi.first]].erase(titr);
			titr = dist[b[tpi.first]].lower_bound(tki);
			if (!dist[b[tpi.first]].empty() && titr!=dist[b[tpi.first]].begin() && prev(titr)->second<=ndi) continue;
			dist[b[tpi.first]][tki] = ndi;
			pq.emplace(make_pair(tki, ndi), b[tpi.first]);
		}
	}
	ll res = LINF;
	for (auto pi : dist[n-1]) res = min(res, pi.second);
	if (res == LINF) res = -1;
	cout << res << endl;
	return 0;
}
