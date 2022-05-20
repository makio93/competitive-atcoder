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

int main() {
	int n, m;
	cin >> n;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	cin >> m;
	vector<int> a(m), b(m);
	dsu dt(n);
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		dt.merge(a[i], b[i]);
	}
	bool ok = true;
	rep(i, n) { if (!dt.same(i, p[i])) ok = false; }
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<pair<int, int>>> g(n);
	dsu dv(n);
	rep(i, m) if (!dv.same(a[i], b[i])) {
		g[a[i]].emplace_back(b[i], i);
		g[b[i]].emplace_back(a[i], i);
		dv.merge(a[i], b[i]);
	}
	vector<int> deg(n);
	rep(i, n) deg[i] = g[i].size();
	vector<int> res;
	queue<int> que;
	rep(i, n) if (deg[i] == 1) que.push(i);
	while (!que.empty()) {
		int val = que.front(); que.pop();
		vector<int> ord;
		function<bool(int,int)> dfs = [&](int vi, int pi) -> bool {
			if (p[vi] == val) return true;
			else {
				for (auto tpi : g[vi]) if (tpi.first != pi) {
					ord.push_back(tpi.second);
					bool res = dfs(tpi.first, vi);
					if (res) return true;
					ord.pop_back();
				}
				return false;
			}
		};
		dfs(val, -1);
		int len = ord.size();
		repr(i, len) {
			swap(p[a[ord[i]]], p[b[ord[i]]]);
			res.push_back(ord[i]+1);
		}
		for (auto tpi : g[val]) if (deg[tpi.first] > 1) {
			deg[tpi.first]--;
			if (deg[tpi.first] == 1) que.push(tpi.first);
		}
	}
	int k = res.size();
	if (k <= (int)(5e5)) {
		cout << k << endl;
		if (k == 0) cout << endl;
		else rep(i, k) printf("%d%c", res[i], (i<k-1?' ':'\n'));
	}
	else cout << -1 << endl;
	return 0;
}
