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
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	int res = 0;
	unordered_set<int> used;
	auto dfs = [&](auto dfs, int di=0, int ri=0) -> void {
		int yi = di - ri, xi = ri;
		if (used.find(a[yi][xi]) != used.end()) return;
		if (di == h+w-2) { ++res; return; }
		used.insert(a[yi][xi]);
		if (yi+1 < h) dfs(dfs, di+1, ri);
		if (xi+1 < w) dfs(dfs, di+1, ri+1);
		used.erase(a[yi][xi]);
	};
	dfs(dfs);
	cout << res << endl;
	return 0;
}
