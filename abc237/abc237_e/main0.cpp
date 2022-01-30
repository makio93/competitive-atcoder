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

// 本番AC

const ll INF = (ll)(1e18);

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];
	vector<vector<pair<int, ll>>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		ll sub = h[vi] - h[ui], cval1 = sub * (sub>0LL ? 2 : 1), cval2 = -sub * (-sub>0LL ? 2 : 1);
		g[ui].emplace_back(vi, cval1);
		g[vi].emplace_back(ui, cval2);
	}
	vector<ll> dist(n, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
	dist[0] = 0;
	que.emplace(0, 0);
	while (!que.empty()) {
		auto [di, vi] = que.top(); que.pop();
		if (dist[vi] != di) continue;
		for (auto tpi : g[vi]) {
			int ti = tpi.first;
			ll ndi = di + tpi.second;
			if (dist[ti] <= ndi) continue;
			dist[ti] = ndi;
			que.emplace(ndi, ti);
		}
	}
	ll mval = INF;
	rep(i, n) mval = min(mval, dist[i]);
	mval *= -1;
	cout << mval << endl;
	return 0;
}
