#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番TLE2,普通にグラフを構築

const ll mod = 998244353LL;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	vector<unordered_set<int>> uv(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		uv[ui].insert(vi);
		uv[vi].insert(ui);
	}
	rep(i, n) rep3(j, i+1, n) if (uv[i].find(j) == uv[i].end()) {
		g[i].push_back(j);
		g[j].push_back(i);
	}
	vector<vector<ll>> dcnt(k+1, vector<ll>(n));
	dcnt[0][0] = 1;
	rep(i, k-1) rep(j, n) for (int t : g[j]) dcnt[i+1][t] = (dcnt[i+1][t] + dcnt[i][j]) % mod;
	for (int t : g[0]) dcnt[k][0] = (dcnt[k][0] + dcnt[k-1][t]) % mod;
	cout << dcnt[k][0] << endl;
	return 0;
}
