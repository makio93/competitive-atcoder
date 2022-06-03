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

vector<ll> col;
vector<int> visited;
ll dfs(vector<vector<int>>& g, int c, int v, int p=-1) {
	if (col[v] != -1) {
		if (col[v] == c) return 1;
		else return 0;
	}
	else {
		bool ok = true;
		for (int to : g[v]) if (col[to] == c) ok = false;
		if (!ok) return 0;
		if (visited[v]!=0) return (visited[v]==1 ? 1 : 0);
		col[v] = c;
		visited[v] = true;
		ll res = 1;
		for (int to : g[v]) {
			if (to == p) continue;
			if (visited[to]) continue;
			ll sum = 0;
			rep(i, 3) if (i!=c) {
				sum += dfs(g, i, to, v);
			}
			res *= sum;
		}
		col[v] = -1;
		if (res == 0) visited[v] = -1;
		else visited[v] = 1;
		return res;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	dsu d(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
		d.merge(ai, bi);
	}
	auto dlst = d.groups();
	int gcnt = (int)(dlst.size());
	ll res = 1;
	col = vector<ll>(n, -1);
	visited = vector<int>(n);
	rep(i1, gcnt) {
		ll vcnt = 0;
		rep(i, 3) {
			visited = vector<int>(n);
			vcnt += dfs(g, i, dlst[i1].front());
		}
		res *= vcnt;
	}
	cout << res << endl;
	return 0;
}
