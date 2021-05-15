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

using mint = modint1000000007;
mint msum = 0;

void dfs(vector<vector<pair<int, ll>>>& g, vector<int>& bcnt, ll wi=0, int d=0, int v=0, int p=-1) {
	if (p != -1) {
		rep(i, 60) if ((wi>>i)&1) bcnt[i] = (d)-bcnt[i];
		//rep(i, 60) if ((wi>>i)&1) bcnt[i]++;
		mint mval = 0;
		rep(i, 60) mval += mint(2).pow(i) * bcnt[i];
		msum += mval;
	}
	int m = g[v].size();
	rep(i, m) {
		int t = g[v][i].first;
		if (t == p) continue;
		dfs(g, bcnt, g[v][i].second, d+1, t, v);
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<pair<int, ll>>> g(n);
	rep(i, n-1) {
		int ui, vi;
		ll wi;
		cin >> ui >> vi >> wi;
		--ui; --vi;
		g[ui].emplace_back(vi, wi);
		g[vi].emplace_back(ui, wi);
	}
	vector<int> bcnt(60);
	dfs(g, bcnt);
	cout << msum.val() << endl;
	return 0;
}
