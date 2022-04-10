// 本番,WA

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

using mint = modint998244353;

struct combination {
	vector<mint> fact, ifact;
	combination(int n) : fact(n+1), ifact(n+1) {
		fact[0] = 1;
		for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
		ifact[n] = fact[n].inv();
		for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k<0 || k>n) return 0;
		return (fact[n] * ifact[k] * ifact[n-k]);
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	vector<unordered_set<int>> g(2*n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
		g[p[i]].insert(p[i]+n);
		g[p[i]+n].insert(p[i]);
	}
	rep(i, n) {
		cin >> q[i];
		q[i]--;
		g[q[i]+n].insert(q[i]);
		g[q[i]].insert(q[i]+n);
	}
	rep(i, n) {
		g[p[i]].insert(q[i]+n);
		g[q[i]+n].insert(p[i]);
	}
	dsu d(2*n);
	vector<bool> visited(2*n);
	auto dfs = [&](auto dfs, int vi, int pi=-1) -> void {
		visited[vi] = true;
		for (int ti : g[vi]) if (ti!=pi && !visited[ti]) {
			d.merge(vi, ti);
			dfs(dfs, ti, vi);
		}
	};
	rep(i, 2*n) if (!visited[i]) dfs(dfs, i);
	auto lst = d.groups();
	mint res = 1;
	combination cb(2*n+1);
	rep(i, (int)(lst.size())) {
		int m = lst[i].size() / 2;
		mint val = 0;
		rep(j, m/2+1) val += cb(m, j);
		res *= val;
	}
	cout << res.val() << endl;
	return 0;
}
