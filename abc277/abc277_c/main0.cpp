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
	int n;
	cin >> n;
	unordered_map<int, unordered_set<int>> g;
	rep(i, n) {
		int ai, bi;
		cin >> ai >> bi;
		g[ai].insert(bi);
		g[bi].insert(ai);
	}
	int res = 1;
	unordered_set<int> visited;
	queue<int> que;
	que.push(1);
	visited.insert(1);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		for (const int& ti : g[vi]) if (visited.find(ti) == visited.end()) {
			res = max(res, ti);
			que.push(ti);
			visited.insert(ti);
		}
	}
	cout << res << endl;
	return 0;
}
