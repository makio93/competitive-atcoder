// 自力WA2

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
	int n, u, v;
	cin >> n >> u >> v;
	--u; --v;
	vector<vector<int>> g(n);
	rep(i, n-1) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> aoki(n, INF), takahashi(n, INF);
	queue<int> que;
	aoki[v] = 0;
	que.push(v);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = aoki[vi], ndi = di + 1;
		for (int ti : g[vi]) if (aoki[ti] > ndi) {
			aoki[ti] = ndi;
			que.push(ti);
		}
	}
	int res = 0;
	takahashi[u] = 0;
	que.push(u);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = takahashi[vi], ndi = di + 1;
		for (int ti : g[vi]) {
			if (takahashi[ti]<=ndi || aoki[ti]<ndi) continue;
			res = max(res, min(aoki[ti], ndi));
			takahashi[ti] = ndi;
			que.push(ti);
		}
	}
	cout << res << endl;
	return 0;
}
