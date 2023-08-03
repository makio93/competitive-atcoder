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

const vector<int> dr = { -1, 0, 1, 0 }, dc = { 0, 1, 0, -1 };
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<vector<bool>>> visited(4, vector<vector<bool>>(n, vector<bool>(m)));
	function<void(int, int, int)> dfs = [&](int ri, int ci, int di) {
		visited[di][ri][ci] = true;
		int tri = ri, tci = ci;
		bool same = true;
		while (s[tri+dr[di]][tci+dc[di]] == '.') {
			tri += dr[di];
			tci += dc[di];
			if (!visited[di][tri][tci]) {
				if (same) same = false;
				visited[di][tri][tci] = true;
			}
		}
		if (same) return;
		rep(i, 4) dfs(tri, tci, i);
	};
	rep(i, 4) dfs(1, 1, i);
	int res = 0;
	rep(i, n) rep(j, m) {
		rep(i2, 4) if (visited[i2][i][j]) {
			++res;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
