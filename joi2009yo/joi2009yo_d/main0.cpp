// 学習0回目,自力AC

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

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<bool>> c(n, vector<bool>(m));
	rep(i, n) rep(j, m) {
		int ci;
		cin >> ci;
		c[i][j] = ci == 1;
	}
	int res = 0;
	rep(i, n) rep(j, m) if (c[i][j]) {
		auto tc = c;
		auto dfs = [&](auto dfs, int yi, int xi) -> int {
			tc[yi][xi] = false;
			const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
			int ret = 0;
			rep(i1, 4) {
				int ny = yi + dy[i1], nx = xi + dx[i1];
				if (ny<0 || ny>=n || nx<0 || nx>=m || !tc[ny][nx]) continue;
				ret = max(ret, dfs(dfs, ny, nx));
			}
			tc[yi][xi] = true;
			return ret + 1;
		};
		res = max(res, dfs(dfs, i, j));
	}
	cout << res << endl;
	return 0;
}
