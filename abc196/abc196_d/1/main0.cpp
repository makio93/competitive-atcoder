// 学習1回目,バチャ本番,自力AC

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
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	int res = 0;
	vector<vector<int>> c(h, vector<int>(w)), tmp(h, vector<int>(w));
	auto dfs = [&](auto dfs, int vi=0, int di=0) -> void {
		if (vi == h*w) {
			if (di < a) return;
			tmp.assign(h, vector<int>(w, 0));
			rep(i, h) rep(j, w) {
				if (tmp[i][j] == 0) tmp[i][j] = c[i][j];
				if (tmp[i][j] == 1) {
					if (j+1>=w || c[i][j+1]!=0 || tmp[i][j+1]!=0) return;
					tmp[i][j+1] = 3;
				}
				if (tmp[i][j] == 2) {
					if (i+1>=h || c[i+1][j]!=0 || tmp[i+1][j]!=0) return;
					tmp[i+1][j] = 3;
				}
			}
			++res;
			return;
		}
		int ri = vi / w, ci = vi % w;
		c[ri][ci] = 0;
		dfs(dfs, vi+1, di);
		if (di == a) return;
		rep3(i1, 1, 3) {
			c[ri][ci] = i1;
			dfs(dfs, vi+1, di+1);
		}
	};
	dfs(dfs);
	cout << res << endl;
	return 0;
}
