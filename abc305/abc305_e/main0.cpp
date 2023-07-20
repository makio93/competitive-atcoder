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

const int INF = (int)(1e9);

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> p(k), h(k);
	rep(i, k) {
		cin >> p[i] >> h[i];
		p[i]--;
	}
	vector<int> dists(n, -1);
	priority_queue<pair<int, int>> pq;
	rep(i, k) {
		dists[p[i]] = h[i];
		pq.emplace(h[i], p[i]);
	}
	while (!pq.empty()) {
		auto [hi, pi] = pq.top(); pq.pop();
		if (dists[pi] != hi) continue;
		int nhi = hi - 1;
		for (const int& ti : g[pi]) if (dists[ti] < nhi) {
			dists[ti] = nhi;
			if (nhi > 0) pq.emplace(nhi, ti);
		}
	}
	vector<int> res;
	rep(i, n) if (dists[i] != -1) res.push_back(i+1);
	int glen = res.size();
	cout << glen << endl;
	rep(i, glen) cout << res[i] << (i<glen-1?' ':'\n');
	return 0;
}
