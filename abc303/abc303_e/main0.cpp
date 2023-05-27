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
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	function<int(int,int)> next_center = [&](int vi, int pi) {
		int ti = g[vi][0] == pi ? g[vi][1] : g[vi][0];
		int ri = g[ti][0] == vi ? g[ti][1] : g[ti][0];
		return ri;
	};
	queue<int> que;
	vector<bool> centers(n);
	rep(i, n) if ((int)(g[i].size()) == 1) {
		que.push(g[i][0]);
		centers[g[i][0]] = true;
		break;
	}
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		for (const int& ti : g[vi]) if ((int)(g[ti].size()) == 2) {
			int ri = next_center(ti, vi);
			if (centers[ri]) continue;
			centers[ri] = true;
			que.push(ri);
		}
	}
	vector<int> res;
	rep(i, n) if (centers[i]) res.push_back((int)(g[i].size()));
	sort(all(res));
	int m = res.size();
	rep(i, m) cout << res[i] << (i<m-1?' ':'\n');
	return 0;
}
