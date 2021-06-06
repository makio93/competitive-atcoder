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

// 本番中、WA

const ll INF = (ll)(1e18);

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	vector<ll> c(m), d(m);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi >> c[i] >> d[i];
		--ai; --bi;
		g[ai].emplace_back(bi, i);
		g[bi].emplace_back(ai, i);
	}
	auto calc = [&](ll tm, int id) -> ll {
		bool ok = false;
		ll res = tm, pval = res + (d[id]/res+1);
		++res;
		while (!ok) {
			ll tval = res + (d[id]/res+1);
			if (tval <= pval) ok = true;
			else {
				++res;
				pval = tval;
			}
		}
		return res;
	};
	vector<ll> dist(n, INF);
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
	que.emplace(0, 0);
	dist[0] = 0;
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		ll di = p.first;
		int v = p.second;
		if (dist[v] != di) continue;
		rep(i, (int)(g[v].size())) {
			int t = g[v][i].first, tid = g[v][i].second;
			ll d2 = calc(di, tid), nd = d2 + (ll)c[tid] + ((ll)d[tid]/(d2+1));
			if (dist[t] <= nd) continue;
			que.emplace(nd, t);
			dist[t] = nd;
		}
	}
	if (dist[n-1] == INF) cout << -1 << endl;
	else cout << dist[n-1] << endl;
	return 0;
}
