// 自力AC1

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
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n-1));
	rep(i, n) rep(j, n-1) {
		cin >> a[i][j];
		a[i][j]--;
	}
	unordered_map<int, vector<int>> g;
	unordered_map<int, int> din, dist;
	rep(i, n) rep(j, n-2) {
		int li1 = i, ri1 = a[i][j], li2 = i, ri2 = a[i][j+1];
		if (li1 > ri1) swap(li1, ri1);
		if (li2 > ri2) swap(li2, ri2);
		g[li1*n+ri1].push_back(li2*n+ri2);
		if (din.find(li1*n+ri1) == din.end()) din[li1*n+ri1] += 0;
		din[li2*n+ri2]++;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (auto pi : din) if (pi.second == 0) {
		pq.emplace(1, pi.first);
		dist[pi.first] = 1;
	}
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int di = pi.first, vi = pi.second;
		if (dist[vi] != di) continue;
		int ndi = di + 1;
		for (auto ti : g[vi]) {
			din[ti]--;
			dist[ti] = max(dist[ti], ndi);
			if (din[ti] == 0) pq.emplace(ndi, ti);
		}
	}
	bool ok = true;
	for (auto pi : din) if (pi.second != 0) {
		ok = false;
		break;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	int res = 0;
	for (auto pi : dist) res = max(res, pi.second);
	cout << res << endl;
	return 0;
}
