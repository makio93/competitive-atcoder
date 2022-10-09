// バチャ本番AC

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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> dlst;
	auto is_square = [](int val) -> int {
		if (val == 0) return val;
		int lval = 0, rval = val + 1;
		while (rval-lval > 1) {
			int cval = lval + (rval-lval) / 2;
			if ((ll)cval*cval == (ll)val) return cval;
			else if ((ll)cval*cval < (ll)val) lval = cval;
			else rval = cval;
		}
		return -1;
	};
	for (int i=0; i*i<=m; ++i) {
		int rval = is_square(m-i*i);
		if (rval!=-1 && i<n && rval<n) dlst.emplace_back(i, rval);
	}
	queue<pair<int, int>> que;
	vector<vector<int>> dist(n, vector<int>(n, INF));
	dist[0][0] = 0;
	que.emplace(0, 0);
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int vi = pi.first, vj = pi.second, di = dist[vi][vj], ndi = di + 1;
		for (const auto& tdi : dlst) for (const int& si : { 1, -1 }) for (const int& sj : { 1, -1 }) {
			int ni = vi + tdi.first * si, nj = vj + tdi.second * sj;
			if (ni<0 || ni>=n || nj<0 || nj>=n || dist[ni][nj]<=ndi) continue;
			dist[ni][nj] = ndi;
			que.emplace(ni, nj);
		}
	}
	rep(i, n) rep(j, n) if (dist[i][j] == INF) dist[i][j] = -1;
	rep(i, n) rep(j, n) cout << dist[i][j] << (j<n-1?' ':'\n');
	return 0;
}
