// 解説AC

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
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> dist(n);
	queue<int> que;
	dist[0] = 1;
	que.push(0);
	dist[n-1] = -1;
	que.push(n-1);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dist[vi];
		for (int ti : g[vi]) if (dist[ti] == 0) {
			dist[ti] = di;
			que.push(ti);
		}
	}
	int cnt = 0;
	rep(i, n) if (dist[i] == 1) ++cnt;
	if (cnt > n-cnt) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
	return 0;
}
