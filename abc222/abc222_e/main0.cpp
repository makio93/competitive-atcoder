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

// 本番AC

const ll mod = 998244353LL;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m);
	rep(i, m) {
		cin >> a[i];
		a[i]--;
	}
	vector<vector<pair<int, int>>> g(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].emplace_back(vi, i);
		g[vi].emplace_back(ui, i);
	}
	vector<int> ecnt(n-1);
	function<bool(int,int,int)> dfs = [&](int v, int p, int d) -> bool {
		if (v == d) return true;
		for (auto tp : g[v]) if (tp.first != p) {
			if (dfs(tp.first, v, d)) {
				ecnt[tp.second]++;
				return true;
			}
		}
		return false;
	};
	rep(i, m-1) dfs(a[i], -1, a[i+1]);
	map<int, ll> vals;
	vals[0] = 1;
	rep(i, n-1) {
		map<int, ll> nvals;
		for (auto pi : vals) {
			nvals[pi.first+ecnt[i]] = (nvals[pi.first+ecnt[i]] + pi.second) % mod;
			nvals[pi.first-ecnt[i]] = (nvals[pi.first-ecnt[i]] + pi.second) % mod;
		}
		swap(vals, nvals);
	}
	if (vals.find(k) != vals.end()) cout << vals[k] << endl;
	else cout << 0 << endl;
	return 0;
}
