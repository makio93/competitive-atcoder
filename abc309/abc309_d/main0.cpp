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
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	vector<vector<int>> g(n1+n2);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<int> dists(n1+n2, INF);
	queue<int> que;
	dists[0] = 0;
	dists[n1+n2-1] = 0;
	que.push(0);
	que.push(n1+n2-1);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dists[vi], ndi = di + 1;
		for (const int& ti : g[vi]) {
			if (dists[ti] <= ndi) continue;
			dists[ti] = ndi;
			que.push(ti);
		}
	}
	int aval = *max_element(dists.begin(), dists.begin()+n1), bval = *max_element(dists.begin()+n1, dists.end());
	cout << (aval+bval+1) << endl;
	return 0;
}
