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

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<unordered_set<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].insert(vi);
		g[vi].insert(ui);
	}
	set<pair<ll, int>> clst;
	vector<ll> csums(n);
	rep(i, n) {
		pair<ll, int> tpi = { 0, i };
		for (const int ti : g[i]) tpi.first += a[ti];
		clst.insert(tpi);
		csums[i] = tpi.first;
	}
	ll res = 0;
	while (!clst.empty()) {
		auto spi = *clst.begin();
		clst.erase(clst.begin());
		res = max(res, spi.first);
		int vi = spi.second;
		csums[vi] = 0;
		for (const int ti : g[vi]) {
			pair<ll, int> tpi = { csums[ti], ti };
			clst.erase(clst.find(tpi));
			tpi.first -= a[vi];
			csums[ti] -= a[vi];
			g[tpi.second].erase(vi);
			clst.insert(tpi);
		}
		g[vi].clear();
	}
	cout << res << endl;
	return 0;
}
