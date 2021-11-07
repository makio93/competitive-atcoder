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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	vector<vector<int>> rg(n);
	rep(i, n) {
		int ki;
		cin >> t[i] >> ki;
		rep(j, ki) {
			int ai;
			cin >> ai;
			--ai;
			rg[i].push_back(ai);
		}
	}
	vector<bool> visited(n);
	queue<int> que;
	visited[n-1] = true;
	que.push(n-1);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		for (int ti : rg[vi]) if (!visited[ti]) {
			visited[ti] = true;
			que.push(ti);
		}
	}
	ll res = 0;
	rep(i, n) if (visited[i]) res += t[i];
	cout << res << endl;
	return 0;
}
