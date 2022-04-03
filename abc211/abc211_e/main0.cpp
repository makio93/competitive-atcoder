// 本番1,WA

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

vector<vector<int>> g;
map<pair<int, int>, ll> memo;
ll dfs(int v, int d) {
	if (memo.find({v, d}) != memo.end()) return memo[{v, d}];
	if (d == 0) return (memo[{v, d}] = 1);
	int len = g[v].size();
	function<ll(int,int)> rec = [&](int li, int lm) {
		if (lm == 0) return dfs(g[v][lm], 0);
		if (li == len-1) return dfs(g[v][li], lm);
		ll val = rec(li+1, lm);
		rep3r(i, 1, lm+1) val += dfs(g[v][li], i) * rec(li+1, lm-i);
		return val;
	};
	ll res = rec(0, d-1);
	return (memo[{v, d}] = res);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<vector<bool>> col(n, vector<bool>(n));
	rep(i, n) rep(j, n) if (s[i][j] == '.') col[i][j] = true;
	g = vector<vector<int>>(n*n);
	dsu d(n*n);
	const vector<int> di = { 0, 1 }, dj = { 1, 0 };
	rep(i, n) rep(j, n) if (col[i][j]) {
		rep(i2, 2) {
			int ni = i + di[i2], nj = j + dj[i2];
			if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
			if (!col[ni][nj]) continue;
			if (d.same(i*n+j, ni*n+nj)) continue;
			g[i*n+j].push_back(ni*n+nj);
			d.merge(i*n+j, ni*n+nj);
		}
	}
	ll res = 0;
	rep(i, n) rep(j, n) if (col[i][j]) res += dfs(i*n+j, k-1);
	cout << res << endl;
	return 0;
}
