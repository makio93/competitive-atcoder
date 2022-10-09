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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> a(n), b(k);
	rep(i, n) cin >> a[i];
	rep(i, k) cin >> b[i];
	vector<int> dist(n, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	if (a[0] == b[0]) dist[0] = 0;
	else dist[0] = -1;
	pq.emplace(dist[0], 0);
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int di = pi.first, vi = pi.second;
		if (dist[vi] != di) continue;
		for (const int& ti : g[vi]) {
			int ndi = di;
			if (di+1<k && a[ti]==b[di+1]) ndi = di + 1;
			if (dist[ti] <= ndi) continue;
			dist[ti] = ndi;
			if (ti != n-1) pq.emplace(dist[ti], ti);
		}
	}
	if (dist[n-1] >= k-1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
