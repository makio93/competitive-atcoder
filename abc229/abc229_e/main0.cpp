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
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
	}
	dsu d(n);
	vector<int> res(n);
	int nval = 0;
	rep3r(i, 1, n) {
		++nval;
		int tlen = g[i].size();
		if (tlen >= 1) {
			d.merge(i, g[i][0]);
			--nval;
		}
		if (tlen > 1) {
			rep3(j, 1, tlen) {
				if (!d.same(i, g[i][j])) --nval;
				d.merge(i, g[i][j]);
			}
		}
		res[i-1] = nval;
	}
	rep(i, n) cout << res[i] << endl;
	return 0;
}
