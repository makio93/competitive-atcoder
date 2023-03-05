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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
	}
	vector<int> dist;
	int res = 0;
	rep(i, n) {
		dist.assign(n, INF);
		queue<int> que;
		dist[i] = 0;
		que.push(i);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[vi], ndi = di + 1;
			for (const int& ti : g[vi]) {
				if (dist[ti] <= ndi) continue;
				dist[ti] = ndi;
				que.push(ti);
			}
		}
		rep(j, n) if (dist[j]>=2 && dist[j]!=INF) ++res;
	}
	cout << res << endl;
	return 0;
}
