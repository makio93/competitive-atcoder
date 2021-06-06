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
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
	}
	int res = 0;
	rep(i, n) {
		vector<int> dist(n, INF);
		queue<int> que;
		que.push(i);
		dist[i] = 0;
		while (!que.empty()) {
			int v = que.front(); que.pop();
			int d = dist[v], nd = d + 1;
			rep(j, (int)(g[v].size())) {
				int t = g[v][j];
				if (dist[t] <= nd) continue;
				que.push(t);
				dist[t] = nd;
			}
		}
		rep(j, n) if (dist[j] != INF) ++res;
	}
	cout << res << endl;
	return 0;
}
