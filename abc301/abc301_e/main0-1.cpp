// 本番WA

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
			}
		}
		dlst[si][ti] = dlst[ti][si] = dist[oids[ti].first][oids[ti].second];
	};
	rep(i, olen) rep3(j, i+1, olen) bfs(i, j);
	rep(i, olen) dlst[i][i] = 0;
	if (dlst[olen-2][olen-1] == INF) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int>> memo(1<<olen, vector<int>(olen, -1));
	auto dfs = [&](auto& dfs, int si, int vi) -> int {
		if (memo[si][vi] != -1) return memo[si][vi];
		if (__builtin_popcount(si) == 1) {
			if (si==(1<<(olen-2)) && vi==olen-1) return memo[si][vi] = 0;
			else return memo[si][vi] = INF;
		}
		if (!(si&(1<<vi))) return memo[si][vi] = INF;
		int rval = INF, pid = si ^ (1<<vi);
		rep(i, olen) if (pid&(1<<i)) {
			rval = min(rval, dfs(dfs, pid, i) + dlst[i][vi]);
		}
		return memo[si][vi] = rval;
	};
	pair<int, int> mval = { -1, 1 };
	rep3(i, 3<<(olen-2), 1<<olen) {
		int rval = dfs(dfs, i, olen-2);
		if (rval <= t) {
			mval = max(mval, { __builtin_popcount(i)-2, -rval });
		}
	}
	cout << mval.first << endl;
	return 0;
}
