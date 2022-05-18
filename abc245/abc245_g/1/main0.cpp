// 学習1回目,自力,TLE

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
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	vector<int> a(n);
	unordered_set<int> b;
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, l) {
		int bi;
		cin >> bi;
		bi--;
		b.insert(bi);
	}
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		int ui, vi, ci;
		cin >> ui >> vi >> ci;
		--ui; --vi;
		g[ui].emplace_back(vi, ci);
		g[vi].emplace_back(ui, ci);
	}
	int sn = max(1, (int)round(sqrt(n)));
	vector<ll> res(n, LINF);
	if (l <= sn) {
		for (auto itr=b.begin(); itr!=b.end(); ++itr) {
			vector<ll> dist(n, LINF);
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
			int bi = *itr;
			dist[bi] = 0;
			pq.emplace(0, bi);
			while (!pq.empty()) {
				auto pi = pq.top(); pq.pop();
				ll di = pi.first; int vi = pi.second;
				if (dist[vi] != di) continue;
				for (auto tpi : g[vi]) {
					ll ndi = di + tpi.second;
					if (dist[tpi.first] <= ndi) continue;
					dist[tpi.first] = ndi;
					pq.emplace(ndi, tpi.first);
					if (a[bi] != a[tpi.first]) res[tpi.first] = min(res[tpi.first], ndi);
				}
			}
		}
	}
	else {
		rep(i, n) {
			vector<ll> dist(n, LINF);
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
			dist[i] = 0;
			pq.emplace(0, i);
			while (!pq.empty()) {
				auto pi = pq.top(); pq.pop();
				ll di = pi.first; int vi = pi.second;
				if (dist[vi] != di) continue;
				for (auto tpi : g[vi]) {
					ll ndi = di + tpi.second;
					if (dist[tpi.first]<=ndi || res[i]<=ndi) continue;
					dist[tpi.first] = ndi;
					pq.emplace(ndi, tpi.first);
					if (b.find(tpi.first)!=b.end() && a[i]!=a[tpi.first]) res[i] = min(res[i], ndi);
				}
			}
		}
	}
	rep(i, n) if (res[i] == LINF) res[i] = -1;
	rep(i, n) printf("%lld%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
