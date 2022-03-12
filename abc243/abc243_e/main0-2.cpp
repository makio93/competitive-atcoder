// 本番2TLE

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

const ll INF = (ll)(1e17);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<ll> c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	dsu ds(n);
	vector<unordered_map<int, ll>> g(n);
	vector<pair<ll, int>> clst;
	rep(i, m) clst.emplace_back(c[i], i);
	sort(all(clst));
	vector<pair<ll, int>> elst;
	rep(i, m) {
		if (ds.same(a[clst[i].second], b[clst[i].second])) {
			elst.push_back(clst[i]);
			continue;
		}
		g[a[clst[i].second]][b[clst[i].second]] = clst[i].first;
		g[b[clst[i].second]][a[clst[i].second]] = clst[i].first;
		ds.merge(a[clst[i].second], b[clst[i].second]);
	}
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	rep(i, n) dist[i][i] = 0;
	rep(i, n) for (auto pi : g[i]) dist[i][pi.first] = pi.second;
	rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min({INF, dist[i][j], dist[i][k]+dist[k][j], dist[j][k]+dist[k][i]});
	int len = elst.size();
	int res = 0;
	rep(i, len) {
		ll ci = elst[i].first;
		int ai = a[elst[i].second], bi = b[elst[i].second];
		if (dist[ai][bi] <= ci) ++res;
		else {
			rep(i, n) rep(j, n) dist[i][j] = min({INF, dist[i][j], dist[i][ai]+ci+dist[bi][j], dist[j][ai]+ci+dist[bi][i]});
		}
	}
	cout << res << endl;
	return 0;
}
