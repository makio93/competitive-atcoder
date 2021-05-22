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
vector<vector<pair<int, int>>> qlst;
vector<int> res;
void dfs(unordered_map<int, int>& vcnt, int v, int p=-1, int d=0) {
	bool single = ((v!=0&&(int)(g[v].size())<=2) || (v==0&&(int)(g[v].size())<=1));
	rep(i, (int)(g[v].size())) {
		int t = g[v][i];
		if (t == p) continue;
		if (single) dfs(vcnt, t, v, d+1);
		else {
			unordered_map<int, int> vcnt2;
			dfs(vcnt2, t, v, d+1);
			for (auto itr=vcnt2.begin(); itr!=vcnt2.end(); ++itr) vcnt[itr->first] += itr->second;
		}
	}
	vcnt[d]++;
	rep(i, (int)(qlst[v].size())) {
		int di = qlst[v][i].first, qi = qlst[v][i].second;
		if (di < d) res[qi] = 0;
		else res[qi] = vcnt[di];
	}
}

int main() {
	int n, q;
	cin >> n;
	g = vector<vector<int>>(n);
	rep3(i, 1, n) {
		int pi;
		cin >> pi;
		--pi;
		g[pi].push_back(i);
		g[i].push_back(pi);
	}
	cin >> q;
	qlst = vector<vector<pair<int, int>>>(n);
	res = vector<int>(q);
	rep(i, q) {
		int ui, di;
		cin >> ui >> di;
		--ui;
		qlst[ui].emplace_back(di, i);
	}
	unordered_map<int, int> vcnt;
	dfs(vcnt, 0);
	rep(i, q) cout << res[i] << endl;
	return 0;
}
