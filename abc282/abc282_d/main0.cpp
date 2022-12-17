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
	vector<int> u(m), v(m);
	vector<vector<int>> g(n);
	dsu d(n);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
		d.merge(u[i], v[i]);
		g[u[i]].push_back(v[i]);
		g[v[i]].push_back(u[i]);
	}
	vector<int> col(n);
	auto dfs = [&](auto dfs, int vi, int ci=1) -> bool {
		col[vi] = ci;
		int nci = -ci;
		for (const int& ti : g[vi]) {
			if (col[ti] != 0) {
				if (col[ti] == nci) continue;
				else return false;
			}
			if (!dfs(dfs, ti, nci)) return false;
		}
		return true;
	};
	bool bin = true;
	rep(i, n) if (col[i] == 0) {
		if (dfs(dfs, i)) continue;
		else {
			bin = false;
			break;
		}
	}
	if (!bin) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> mcnt(n);
	rep(i, n) mcnt[d.leader(i)] += (int)(g[i].size());
	rep(i, n) mcnt[i] /= 2;
	auto alst = d.groups();
	int glen = alst.size();
	vector<int> glst;
	rep(i, glen) glst.push_back((int)(alst[i].size()));
	vector<int> gsum(glen+1);
	rep(i, glen) gsum[i+1] += gsum[i] + glst[i];
	ll res = 0;
	repr(i, glen-1) res += (ll)(gsum[glen] - gsum[i+1]) * glst[i];
	unordered_map<int, int> pcols;
	rep(i, n) if (col[i] == 1) pcols[d.leader(i)]++;
	for (const auto& pi : pcols) {
		int pval = pi.second, nval = d.size(pi.first) - pval;
		res += (ll)pval * nval - mcnt[pi.first];
	}
	cout << res << endl;
	return 0;
}
