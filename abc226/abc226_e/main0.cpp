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

// 本番WA

const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> deg(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
		deg[ui]++; deg[vi]++;
	}
	set<int> visited;
	rep(i, n) visited.insert(i);
	bool one = true;
	while (one) {
		one = false;
		set<int> evis;
		for (int i : visited) if (deg[i] == 1) {
			evis.insert(i);
			deg[i]--;
			for (int j : g[i]) if (visited.find(j) != visited.end()) {
				deg[j]--;
				break;
			}
			one = true;
		}
		for (int i : evis) visited.erase(i);
	}
	bool ok = true;
	for (int i : visited) if (deg[i] != 2) ok = false; 
	if (!ok) {
		cout << 0 << endl;
		return 0;
	}
	int rcnt = 0;
	function<void(int,int)> dfs = [&](int v, int p) {
		visited.erase(v);
		int tcnt = 0;
		for (int ti : g[v]) if (ti!=p && visited.find(ti)!=visited.end()) {
			if (tcnt > 0) {
				ok = false;
				return;
			}
			++tcnt;
			dfs(ti, v);
		}
	};
	while (!visited.empty()) {
		int i = *visited.begin();
		dfs(i, -1);
		if (!ok) {
			cout << 0 << endl;
			return 0;
		}
		++rcnt;
	}
	ll res = 1;
	rep(i, rcnt) res = res * 2 % mod;
	cout << res << endl;
	return 0;
}
