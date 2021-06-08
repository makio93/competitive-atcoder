#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

const ll INF = (ll)(1e15);

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		--ai; --bi;
		g[ai].emplace_back(bi, ci);
		g[bi].emplace_back(ai, ci);
	}
	vector<ll> dists(n, INF), distt(n, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
	que.emplace(0, 0);
	dists[0] = 0;
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		ll d = p.first; int v = p.second;
		if (dists[v] != d) continue;
		rep(i, (int)(g[v].size())) {
			int t = g[v][i].first, tc = g[v][i].second;
			ll nd = d + tc;
			if (dists[t] <= nd) continue;
			que.emplace(nd, t);
			dists[t] = nd;
		}
	}
	que.emplace(0, n-1);
	distt[n-1] = 0;
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		ll d = p.first; int v = p.second;
		if (distt[v] != d) continue;
		rep(i, (int)(g[v].size())) {
			int t = g[v][i].first, tc = g[v][i].second;
			ll nd = d + tc;
			if (distt[t] <= nd) continue;
			que.emplace(nd, t);
			distt[t] = nd;
		}
	}
	rep(i, n) cout << (dists[i] + distt[i]) << endl;
	return 0;
}
