// 解説AC

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

const int INF = (int)(1e9);
const ll mod = 998244353LL;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> u(m), v(m);
	rep(i, m) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	set<pair<int, int>> uv;
	rep(i, m) {
		uv.emplace(u[i], v[i]);
		uv.emplace(v[i], u[i]);
	}
	vector<int> dist(n, INF);
	unordered_set<int> unused;
	rep3(i, 1, n) unused.insert(i);
	queue<int> que;
	dist[0] = 0;
	que.push(0);
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dist[vi], ndi = di + 1;
		auto itr = unused.begin();
		while (itr != unused.end()) {
			int ti = *itr;
			if (uv.find({ vi, ti }) != uv.end()) {
				++itr;
				continue;
			}
			dist[ti] = ndi;
			que.push(ti);
			itr = unused.erase(itr);
		}
	}
	if (dist[n-1] == INF) {
		cout << -1 << endl;
		return 0;
	}
	int tar = dist[n-1];
	vector<unordered_set<int>> tlst(tar+1);
	rep(i, n) if (dist[i] < tar+1) tlst[dist[i]].insert(i);
	vector<unordered_set<int>> ng(n);
	rep(i, m) {
		ng[u[i]].insert(v[i]);
		ng[v[i]].insert(u[i]);
	}
	vector<ll> dp(n);
	dp[0] = 1;
	rep(i, tar) {
		ll sum = 0;
		for (const int& ti : tlst[i]) sum = (sum + dp[ti]) % mod;
		for (const int& ti : tlst[i+1]) {
			ll sub = 0;
			for (const int& pi : ng[ti]) if (tlst[i].find(pi) != tlst[i].end()) sub = (sub + dp[pi]) % mod;
			dp[ti] = (sum - sub + mod) % mod;
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
