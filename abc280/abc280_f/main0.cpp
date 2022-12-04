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
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<pair<int, int>>> g(n);
	dsu d(n);
	rep(i, m) {
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		--ai; --bi;
		g[ai].emplace_back(bi, ci);
		g[bi].emplace_back(ai, -ci);
		d.merge(ai, bi);
	}
	unordered_set<int> isinf;
	vector<ll> dist(n, -LINF);
	rep(i, n) if (dist[i]==-LINF && isinf.find(d.leader(i))==isinf.end()) {
		queue<int> que;
		dist[i] = 0;
		que.push(i);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			ll di = dist[vi];
			for (const auto& pi : g[vi]) {
				int ti = pi.first, ri = pi.second;
				ll ndi = di + ri;
				if (dist[ti] != -LINF) {
					if (dist[ti] == ndi) continue;
					isinf.insert(d.leader(i));
					break;
				}
				dist[ti] = ndi;
				que.push(ti);
			}
			if (isinf.find(d.leader(i)) != isinf.end()) break;
		}
	}
	rep(i, q) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		if (!d.same(xi, yi)) cout << "nan" << endl;
		else if (isinf.find(d.leader(xi)) != isinf.end()) cout << "inf" << endl;
		else cout << (dist[yi]-dist[xi]) << endl;
	}
	return 0;
}
