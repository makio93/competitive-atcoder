// 本番WA1

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
	vector<vector<pair<int, int>>> g(n);
	dsu dt(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].emplace_back(bi, i);
		g[bi].emplace_back(ai, i);
		dt.merge(ai, bi);
	}
	bool ok = true;
	rep(i, n) {
		if (!dt.same(i, p[i])) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> res;
	rep(i, n) if (p[i] != i) {
		vector<int> dist(n, (int)(1e9));
		queue<int> que;
		int tarv = -1;
		dist[i] = 0;
		que.push(i);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[vi], nd = di + 1;
			for (auto pi : g[vi]) {
				int ti = pi.first;
				if (dist[ti] <= nd) continue;
				dist[ti] = nd;
				if (p[ti] == i) {
					tarv = ti;
					continue;
				}
				que.push(ti);
			}
		}
		int vpos = tarv;
		while (vpos != i) {
			int di = dist[vpos], nd = di - 1;
			for (auto pi : g[vpos]) if (dist[pi.first] == nd) {
				res.push_back(pi.second+1);
				swap(p[pi.first], p[vpos]);
				vpos = pi.first;
				break;
			}
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
