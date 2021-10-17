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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> din(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		din[bi]++;
	}
	vector<int> res;
	priority_queue<int, vector<int>, greater<int>> que;
	rep(i, n) if (din[i] == 0) que.push(i);
	while (!que.empty()) {
		int v = que.top(); que.pop();
		res.push_back(v+1);
		for (int ti : g[v]) {
			din[ti]--;
			if (din[ti] == 0) que.push(ti);
		}
	}
	if ((int)(res.size()) < n) cout << -1 << endl;
	else rep(i, n) printf("%d%c", res[i], (i<n-1?' ':'\n'));
	return 0;
}
