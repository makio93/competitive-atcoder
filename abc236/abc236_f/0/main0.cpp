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

// 本番後,自力考察,誤答

const ll INF = (ll)(1e15);

int main() {
	int n;
	cin >> n;
	vector<int> c(1<<n);
	rep3(i, 1, (1<<n)) cin >> c[i];
	vector<ll> dist((1<<n), INF);
	vector<int> from((1<<n), -1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
	dist[0] = 0;
	que.emplace(0, 0);
	while (!que.empty()) {
		auto [di, vi] = que.top(); que.pop();
		rep3(i, 1, (1<<n)) {
			int ni = vi ^ i;
			ll ndi = di + c[i];
			if (dist[ni] <= ndi) continue;
			dist[ni] = ndi;
			from[ni] = vi;
			que.emplace(ndi, ni);
		}
	}
	vector<bool> searched(1<<n);
	rep3(i, 1, (1<<n)) searched[from[i]] = true;
	vector<int> svi;
	rep(i, (1<<n)) if (!searched[i]) svi.push_back(i);
	ll res = 0;
	vector<bool> visited(1<<n);
	visited[0] = true;
	for (int si : svi) if (!visited[si]) {
		int vi = si;
		while (!visited[vi]) {
			visited[vi] = true;
			vi = from[vi];
		}
		res += dist[si] - dist[vi];
	}
	cout << res << endl;
	return 0;
}
