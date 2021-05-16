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

// 解説を見てから実装、AC

const ll mod = (ll)(1e9) + 7;

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
	queue<int> que;
	vector<ll> dist(n, -1);
	que.push(0);
	dist[0] = 0;
	while (!que.empty()) {
		ll v = que.front(); que.pop();
		ll d = dist[v];
		for (auto nv : g[v]) {
			int t = nv.first; ll nw = nv.second;
			if (dist[t] != -1) continue;
			que.push(t);
			dist[t] = d ^ nw;
		}
	}
	ll val = 0;
	rep(i, 60) {
		vector<int> bcnt(2);
		rep(j, n) bcnt[(dist[j]>>i)&1LL]++;
		val = (val + ((1LL<<i) % mod) * bcnt[0] % mod * bcnt[1]) % mod;
	}
	cout << val << endl;
	return 0;
}
