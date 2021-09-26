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

int n;
vector<ll> csum;
vector<int> vcnt;
vector<vector<int>> g;
ll dfs(int v=0, int p=-1) {
	ll res = 0;
	vcnt[v]++;
	for (int t : g[v]) if (t != p) {
		ll val = dfs(t, v);
		val += vcnt[t];
		res += val;
		vcnt[v] += vcnt[t];
	}
	csum[v] = res;
	return res;
}

vector<ll> dsum;
void dfs2(int v=0, int p=-1) {
	for (int t : g[v]) if (t != p) {
		dsum[t] = dsum[v] - (vcnt[t]) + (n - vcnt[t]);
		dfs2(t, v);
	}
}

int main() {
	cin >> n;
	g = vector<vector<int>>(n);
	rep(i, n-1) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	csum = vector<ll>(n);
	vcnt = vector<int>(n);
	dfs();
	dsum = vector<ll>(n);
	dsum[0] = csum[0];
	dfs2();
	rep(i, n) cout << dsum[i] << endl;
	return 0;
}
