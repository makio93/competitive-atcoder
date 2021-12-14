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

// 本番実装,解答1,最終提出

const int N = 400, M = 1995;

int main() {
	int n = N, m = M;
	vector<int> x(n), y(n), u(m), v(m);
	rep(i, n) cin >> x[i] >> y[i];
	vector<vector<pair<int, int>>> g(n);
	rep(i, m) {
		cin >> u[i] >> v[i];
		g[u[i]].emplace_back(v[i], i);
		g[v[i]].emplace_back(u[i], i);
	}
	vector<int> d(m);
	rep(i, m) d[i] = ((int)round(sqrt((x[u[i]]-x[v[i]])*(x[u[i]]-x[v[i]])+(y[u[i]]-y[v[i]])*(y[u[i]]-y[v[i]])))) * 2;
	unordered_set<int> eids;
	rep(i, m) {
		int li;
		cin >> li;
		d[i] = li;
		dsu ufd(n);
		rep(j, i) if (eids.find(j) != eids.end()) ufd.merge(u[j], v[j]);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
		rep3(j, i, m) que.emplace(d[j], j);
		bool taken = false;
		while (!que.empty()) {
			auto pi = que.top(); que.pop();
			int di = pi.first, id = pi.second;
			if (ufd.same(u[id], v[id])) continue;
			ufd.merge(u[id], v[id]);
			if (id == i) taken = true;
		}
		if (taken) eids.insert(i);
		if (taken) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
