// 本番TLE

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
using mint = modint998244353;

int main() {
	int n, m, a, b, c, d, e, f;
	cin >> n >> m >> a >> b >> c >> d >> e >> f;
	set<pair<int, int>> xy;
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		xy.emplace(xi, yi);
	}
	map<tuple<int, int, int>, mint> memo;
	auto dfs = [&](auto dfs, int xi, int yi, int di) -> mint {
		if (memo.find({ xi, yi, di }) != memo.end()) return memo[{ xi, yi, di }];
		if (xy.find({ xi, yi }) != xy.end()) return memo[{ xi, yi, di }] = 0;
		if (di == 0) return memo[{ xi, yi, di }] = 1;
		if (xi<-INF || xi>INF || yi<-INF || yi>INF) return memo[{ xi, yi, di }] = mint(3).pow(di);
		mint rval = dfs(dfs, xi+a, yi+b, di-1) + dfs(dfs, xi+c, yi+d, di-1) + dfs(dfs, xi+e, yi+f, di-1);
		return memo[{ xi, yi, di }] = rval;
	};
	cout << dfs(dfs, 0, 0, n).val() << endl;
	return 0;
}
