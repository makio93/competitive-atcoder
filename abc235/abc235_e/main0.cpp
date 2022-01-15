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

// 本番,未完成

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<int> a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		--a[i]; --b[i];
	}
	vector<map<int, int>> g(n);
	dsu dmemo(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	rep(i, m) pq.emplace(c[i], i);
	rep(i, m) {
		auto [ci, id] = pq.top(); pq.pop();
		if (dmemo.same(a[id], b[id])) continue;
		g[a[id]][b[id]] = ci;
		g[b[id]][a[id]] = ci;
		dmemo.merge(a[id], b[id]);
	}
	vector<int> depth(n), parents(n);
	vector<ll> pdist(n, (ll)(1e18));
	function<void(int,int,int)> dfs = [&](int v, int p, int d) -> void {
		parents[v] = p;
		depth[v] = d;
		for (auto tpi : g[v]) if (tpi.first!=p && tpi.first!=v) {
			pdist[tpi.first] = tpi.second;
			dfs(tpi.first, v, d+1);
		}
	};
	dfs(0, -1, 0);
	int ki = 0, kval = 1;
	while (kval <= n) {
		kval *= 2;
		++ki;
	}
	vector<vector<int>> dp(ki+1, vector<int>(n, -1));
	vector<vector<ll>> dist(ki+1, vector<ll>(n, (ll)(1e18)));
	rep(i, n) dp[0][i] = parents[i];
	rep(i, n) dist[0][i] = pdist[i];
	rep(i, ki) rep(j, n) {
		if (dp[i][j] == -1) continue;
		dp[i+1][j] = dp[i][dp[i][j]];
		dist[i+1][j] = min((ll)(1e18), dist[i][j]+dist[i][dp[i][j]]);
	}
	rep(i, q) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		--ui; --vi;
		if (g[ui].find(vi) == g[ui].end()) cout << "No" << endl;
		else {
			/*
			ll dcnt = 0;
			if (depth[ui] > depth[vi]) swap(ui, vi);
			repr(i, ki+1) {
				if (((depth[vi]-depth[ui])>>i)&1) {
					dcnt += dist[i][vi];
					vi = dp[i][vi];
				}
			}
			while (ui != vi) {
				dcnt += dist[0][ui];
				dcnt += dist[0][vi];
				ui = dp[0][ui];
				vi = dp[0][vi];
			}
			*/
			if (g[ui][vi] <= (ll)wi) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
 	}
	return 0;
}
