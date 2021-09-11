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

// 本番,TLE

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> s(m), t(m);
	vector<unordered_set<int>> g(n);
	rep(i, m) {
		cin >> s[i] >> t[i];
		s[i]--; t[i]--;
		g[s[i]].insert(t[i]);
	}
	vector<int> ans(m);
	rep3(i, -1, m) {
		if (i >= 0) g[s[i]].erase(t[i]);
		vector<int> dist(n, INF);
		queue<int> que;
		que.push(0);
		dist[0] = 0;
		while (!que.empty()) {
			int v = que.front(); que.pop();
			int d = dist[v], nd = d + 1;
			for (int t : g[v]) if (dist[t] > nd) {
				dist[t] = nd;
				que.push(t);
			}
		}
		if (i == -1) {
			if (dist[n-1] == INF) {
				rep(i, m) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
		else {
			if (dist[n-1] == INF) ans[i] = -1;
			else ans[i] = dist[n-1];
			g[s[i]].insert(t[i]);
		}
	}
	rep(i, m) cout << ans[i] << endl;
	return 0;
}
