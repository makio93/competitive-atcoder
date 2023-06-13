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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ui, vi, ti;
		cin >> ui >> vi >> ti;
		--ui; --vi;
		g[ui].emplace_back(vi, ti);
		g[vi].emplace_back(ui, ti);
	}
	vector<ll> dist(n, LINF), avals(n);
	priority_queue<pair<pair<ll, ll>, int>, vector<pair<pair<ll, ll>, int>>, greater<pair<pair<ll, ll>, int>>> pq;
	dist[0] = 0;
	avals[0] = a[0];
	pq.emplace(make_pair(0, a[0]), 0);
	while (!pq.empty()) {
		auto [pi, vi] = pq.top(); pq.pop();
		auto [di, ai] = pi;
		if (dist[vi] != di || avals[vi] != ai) continue;
		for (const auto [ti, tci] : g[vi]) {
			ll ndi = di + tci, nai = ai + a[ti];
			if (dist[ti] < ndi) continue;
			if (dist[ti] == ndi && avals[ti] >= nai) continue;
			dist[ti] = ndi;
			avals[ti] = nai;
			pq.emplace(make_pair(ndi, nai), ti);
		}
	}
	cout << avals[n-1] << endl;
	return 0;
}
