// 解説を見てから実装、AC

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

ll calc(vector<vector<int>>& g, vector<int>& g2, vector<int>& cal, int d=0) {
	int n = g.size(), n2 = g2.size();
	if (d == n2) {
		bool ok = true;
		rep(i, n2) for (int t : g[g2[i]]) if (cal[t] == cal[g2[i]]) ok = false;
		return (ok ? 1LL : 0LL);
	}
	else {
		ll res = 0;
		rep(i, 3) {
			bool ok = true;
			for (int t : g[g2[d]]) if (cal[t] == i) ok = false;
			if (!ok) continue;
			cal[g2[d]] = i;
			res += calc(g, g2, cal, d+1);
			cal[g2[d]] = -1;
		}
		return res;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	dsu d(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
		d.merge(ai, bi);
	}
	ll res = 1;
	for (auto g2 : d.groups()) {
		vector<int> cal(n, -1);
		res *= calc(g, g2, cal);
	}
	cout << res << endl;
	return 0;
}
