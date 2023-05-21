// 自力AC

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
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int main() {
	int h, w, t;
	cin >> h >> w >> t;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	vector<pair<int, int>> oids;
	int sy = -1, sx = -1, gy = -1, gx = -1;
	rep(i, h) rep(j, w) {
		if (a[i][j] == 'S') sy = i, sx = j;
		else if (a[i][j] == 'G') gy = i, gx = j;
		else if (a[i][j] == 'o') oids.emplace_back(i, j);
	}
	oids.emplace_back(sy, sx);
	oids.emplace_back(gy, gx);
	int olen = oids.size();
	vector<vector<int>> dlst(olen, vector<int>(olen));
	auto bfs = [&](int si, int ti) -> void {
		vector<vector<int>> dist(h, vector<int>(w, INF));
		queue<pair<int, int>> que;
		que.emplace(oids[si].first, oids[si].second);
		dist[oids[si].first][oids[si].second] = 0;
		while (!que.empty()) {
			auto vi = que.front(); que.pop();
			int di = dist[vi.first][vi.second], ndi = di + 1;
			rep(i2, 4) {
				int nyi = vi.first + dy[i2], nxi = vi.second + dx[i2];
				if (nyi<0 || nyi>=h || nxi<0 || nxi>=w || a[nyi][nxi]=='#' || dist[nyi][nxi]<=ndi) continue;
				dist[nyi][nxi] = ndi;
				que.emplace(nyi, nxi);
			}
		}
		dlst[si][ti] = dist[oids[ti].first][oids[ti].second];
	};
	rep(i, olen) rep(j, olen) bfs(i, j);
	if (dlst[olen-2][olen-1] == INF) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int>> memo(1<<olen, vector<int>(olen, INF));
	auto dfs = [&](auto& dfs, int si, int vi) -> int {
		if (memo[si][vi] != INF) return memo[si][vi];
		if (!(si&(1<<(olen-2))) || !(si&(1<<vi))) return memo[si][vi] = INF-1;
		if (si==1<<(olen-2) && vi==olen-2) return memo[si][vi] = 0;
		int rval = INF-1;
		rep(i, olen) if ((si^(1<<vi))&(1<<i)) rval = min(rval, dfs(dfs, si^(1<<vi), i) + dlst[i][vi]);
		return memo[si][vi] = rval;
	};
	int mval = -1;
	rep(i, 1<<(olen-2)) {
		int rval = dfs(dfs, i^(1<<(olen-2))^(1<<(olen-1)), olen-1);
		if (rval <= t) mval = max(mval, __builtin_popcount(i));
	}
	cout << mval << endl;
	return 0;
}
