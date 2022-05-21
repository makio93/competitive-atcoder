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

const ll LINF = (ll)(1e18);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> c(m);
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi >> c[i];
		--ai; --bi;
		g[ai].emplace_back(bi, i);
		g[bi].emplace_back(ai, i);
	}
	vector<ll> dist(n, LINF);
	vector<int> pre(n, -1);
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
	dist[0] = 0;
	pq.emplace(0, make_pair(0, -1));
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		ll di = pi.first; int vi = pi.second.first, fi = pi.second.second;
		if (dist[vi]!=di || pre[vi]!=fi) continue;
		for (auto tpi : g[vi]) {
			ll ndi = di + c[tpi.second]; int ti = tpi.first;
			if (dist[ti] <= ndi) continue;
			dist[ti] = ndi;
			pre[ti] = tpi.second;
			pq.emplace(ndi, make_pair(ti, tpi.second));
		}
	}
	rep3(i, 1, n) printf("%d%c", pre[i]+1, (i<n-1?' ':'\n'));
	return 0;
}
