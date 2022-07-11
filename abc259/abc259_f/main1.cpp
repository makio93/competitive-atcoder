// 解説AC

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
	int n;
	cin >> n;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<vector<pair<int, int>>> g(n);
	rep(i, n-1) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		--ui, --vi;
		g[ui].emplace_back(vi, wi);
		g[vi].emplace_back(ui, wi);
	}
	vector<ll> ldp(n, -LINF), udp(n, -LINF);
	auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
		ll val = 0;
		vector<ll> slst;
		for (auto tpi : g[vi]) if (tpi.first != pi) {
			dfs(dfs, tpi.first, vi);
			val += udp[tpi.first];
			slst.push_back(ldp[tpi.first]+tpi.second-udp[tpi.first]);
		}
		if (d[vi]-1 >= 0) ldp[vi] = val;
		udp[vi] = val;
		if (!slst.empty()) sort(slst.rbegin(), slst.rend());
		int m = slst.size();
		rep(i, m) {
			if (slst[i] < 0) break;
			if (i+1 <= d[vi]) udp[vi] += slst[i];
			if (i+1 < d[vi]) ldp[vi] += slst[i];
		}
	};
	dfs(dfs);
	cout << max(ldp[0], udp[0]) << endl;
	return 0;
}
