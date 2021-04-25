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
	queue<int> que;
	vector<int> dist(n, (int)(1e9));
	que.push(0);
	dist[0] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist[v], nd = d + 1;
		for (auto to : g[v]) {
			if (dist[to] <= nd) continue;
			que.push(to);
			dist[to] = nd;
		}
	}
	pair<int, int> mval = { -1, -1 };
	rep(i, n) mval = max(mval, { dist[i], i });
	dist = vector<int>(n, (int)(1e9));
	que.push(mval.second);
	dist[mval.second] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist[v], nd = d + 1;
		for (auto to : g[v]) {
			if (dist[to] <= nd) continue;
			que.push(to);
			dist[to] = nd;
		}
	}
	mval = { -1, -1 };
	rep(i, n) mval = max(mval, { dist[i], i });
	cout << (mval.first+1) << endl;
	return 0;
}
