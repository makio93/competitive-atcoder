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
	int n, t, m;
	cin >> n >> t >> m;
	vector<int> a(m), b(m);
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	vector<vector<bool>> oks(n, vector<bool>(n, true));
	rep(i, m) oks[a[i]][b[i]] = oks[b[i]][a[i]] = false;
	int res = 0;
	vector<int> rlst(n, -1);
	function<void(int, int)> dfs = [&](int vi, int ri) {
		if (vi == n) {
			++res;
			return;
		}
		if (t-ri < n-vi) {
			rep(i, ri) {
				bool ng = false;
				rep(j, vi) if (!oks[vi][j] && rlst[j]==i) ng = true;
				if (ng) continue;
				rlst[vi] = i;
				dfs(vi+1, ri);
				rlst[vi] = -1;
			}
		}
		if (ri < t) {
			rlst[vi] = ri;
			dfs(vi+1, ri+1);
			rlst[vi] = -1;
		}
	};
	dfs(0, 0);
	cout << res << endl;
	return 0;
}
