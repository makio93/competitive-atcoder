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

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	vector<unordered_set<int>> g(n);
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		g[yi].insert(xi);
	}
	vector<int> din(n);
	rep(i, n) for (const int& ti : g[i]) din[ti]++;
	if (count(all(din), 0) != 1) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> dist(n, -INF);
	queue<int> que;
	rep(i, n) if (din[i] == 0) {
		dist[i] = 0;
		que.push(i);
	}
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dist[vi], ndi = di + 1;
		for (const int& ti : g[vi]) {
			if (dist[ti] < ndi) dist[ti] = ndi;
			din[ti]--;
			if (din[ti] == 0) que.push(ti);
		}
	}
	vector<int> vcnt(n);
	rep(i, n) {
		if (dist[i] == -INF) {
			cout << "No" << endl;
			return 0;
		}
		vcnt[dist[i]]++;
	}
	rep(i, n) if (vcnt[i] != 1) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> vids(n), res(n);
	rep(i, n) vids[dist[i]] = i;
	reverse(all(vids));
	rep(i, n) res[vids[i]] = i + 1;
	cout << "Yes" << endl;
	rep(i, n) cout << res[i] << (i<n-1?' ':'\n');
	return 0;
}
