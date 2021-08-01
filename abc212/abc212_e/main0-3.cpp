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

// 本番,未完成,ダブリングしようとした

const ll mod = 998244353LL;
int n;
map<pair<pair<int, int>, ll>> memo;
vector<vector<int>> g;
ll calc(int v, int p, int ki) {
	if (memo.find({{v, p}, ki}) != memo.end()) return memo[{{v, p},ki}];
	if (ki == 0) {
		ll res = 0;
		rep(int t : g[v]) if (t == p) res++;
		return {memo[{{v, p}, ki}] = res};
	}
	else {
		ll res = 0;
		rep(i, n) res = (res + calc(v, i, ki-1) * calc(i, p, ki-1)) % mod;
		return { memo[{{v, p}, ki}] = res };
	}
}

int main() {
	int m, k;
	cin >> n >> m >> k;
	g = vector<vector<int>>(n);
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
	ll res = 0;
	rep(i, 16) {
		if ((k>>i)&1) res = res + calc(0, 0, )
	}
	cout << calc(0, 0, ) << endl;
	return 0;
}
