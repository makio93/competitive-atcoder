// 本番AC

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

const ll mod = (ll)(1e9) + 7;
const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g[ai].push_back(bi);
		g[bi].push_back(ai);
	}
	vector<ll> dp(n);
	vector<int> dist(n, INF);
	queue<int> que;
	que.push(0);
	dp[0] = 1;
	dist[0] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		ll val = dp[v]; int d = dist[v], nd = d + 1;
		for (int t : g[v]) {
			if (dist[t] < nd) continue;
			dp[t] = (dp[t] + val) % mod;
			if (dist[t] == nd) continue;
			que.push(t);
			dist[t] = nd;
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
