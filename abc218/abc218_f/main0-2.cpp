#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,WA

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> s(m), t(m);
	vector<unordered_set<int>> g(n);
	map<pair<int, int>, int> eid;
	rep(i, m) {
		cin >> s[i] >> t[i];
		s[i]--; t[i]--;
		g[s[i]].insert(t[i]);
		eid[{s[i],t[i]}] = i;
	}
	vector<int> ans(m);
	unordered_set<int> erest;
	rep(i, m) erest.insert(i);
	vector<vector<int>> dist(m+1, vector<int>(n, INF));
	queue<pair<int, int>> que;
	que.emplace(m, 0);
	dist[m][0] = 0;
	while (!que.empty()) {
		auto [mi, vi] = que.front(); que.pop();
		int d = dist[mi][vi], nd = d + 1;
		for (auto t : g[vi]) if (dist[mi][t] > nd) {
			if (eid[{vi,t}] == mi) continue;
			que.emplace(mi, t);
			dist[mi][t] = nd;
		}
		if (mi == m) {
			for (auto t : g[vi]) {
				int ei = eid[{vi,t}];
				for (auto t2 : g[vi]) if (t2 != t) {
					if (eid[{vi,t2}] == mi) continue;
					que.emplace(ei, t2);
					dist[ei][t2] = nd;
					if (erest.find(ei) != erest.end()) erest.erase(ei);
				}
			}
		}
	}
	if (dist[m][n-1] == INF) dist[m][n-1] = -1;
	rep(i, m) {
		if (erest.find(i) != erest.end()) ans[i] = dist[m][n-1];
		else {
			if (dist[i][n-1] == INF) ans[i] = -1;
			else ans[i] = dist[i][n-1];
		}
	}
	rep(i, m) cout << ans[i] << endl;
	return 0;
}
