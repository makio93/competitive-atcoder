// 本番終了後,ほぼ自力考察,AC

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
	vector<int> dist(n, INF);
	unordered_set<int> slst;
	queue<int> que;
	que.push(0);
	dist[0] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist[v], nd = d + 1;
		for (int t : g[v]) if (dist[t] > nd) {
			que.push(t);
			dist[t] = nd;
			slst.insert(eid[{v,t}]);
		}
	}
	vector<int> ans(m);
	rep(i, m) {
		if (slst.find(i) == slst.end()) ans[i] = dist[n-1];
		else {
			g[s[i]].erase(t[i]);
			vector<int> dist2(n, INF);
			queue<int> que2;
			que2.push(0);
			dist2[0] = 0;
			while (!que2.empty()) {
				int v = que2.front(); que2.pop();
				int d = dist2[v], nd = d + 1;
				for (int t : g[v]) if (dist2[t] > nd) {
					que2.push(t);
					dist2[t] = nd;
				}
			}
			ans[i] = dist2[n-1];
			g[s[i]].insert(t[i]);
		}
	}
	rep(i, m) if (ans[i] == INF) ans[i] = -1;
	rep(i, m) cout << ans[i] << endl;
	return 0;
}
