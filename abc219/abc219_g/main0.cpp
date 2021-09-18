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

// 本番実装,未完成

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	unordered_set<int> vs1, vs2;
	rep(i, n) {
		int di = g[i].size();
		if ((ll)di*di <= (ll)n) vs1.insert(i);
		else vs2.insert(i);
	}
	unordered_map<int, vector<int>> g1, g2;
	unordered_map<int, vector<int>> tobig;
	for (int vi : vs1) g1[vi] = g[vi];
	for (int vi : vs2) for (int vi2 : g[vi]) {
		if (vs2.find(vi2) != vs2.end()) g2[vi].push_back(vi2);
		else tobig[vi2].push_back(vi);
	}
	vector<int> col(n), tim(n, -1);
	rep(i, n) col[i] = i + 1;
	vector<int> x(q);
	rep(i, q) {
		cin >> x[i];
		x[i]--;
	}
	rep(i, q) {
		if (vs1.find(x[i]) != vs1.end()) {
			pair<int, int> cti = { tim[x[i]], col[x[i]] };
			for (int bi : tobig[x[i]]) cti = max(cti, { tim[bi], col[bi] });
			tim[x[i]] = i;
			col[x[i]] = cti.second;
			for (int vi : g1[x[i]]) {
				tim[vi] = tim[x[i]];
				col[vi] = col[x[i]];
			}
		}
		else {
			tim[x[i]] = i;
			for (int vi : g2[x[i]]) {
				tim[vi] = tim[x[i]];
				col[vi] = col[x[i]];
			}
		}
	}
	for (int vi : vs1) {
		pair<int, int> cti = { tim[vi], col[vi] };
		for (int bi : tobig[vi]) cti = max(cti, { tim[bi], col[bi] });
		tim[vi] = cti.first;
		col[vi] = cti.second;
	}
	rep(i, n) printf("%d%c", col[i], (i<n-1?' ':'\n'));
	return 0;
}
