// 本番WA

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
	int m, n = 9;
	cin >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	vector<int> vals(n, 8);
	rep(i, n-1) {
		int pi;
		cin >> pi;
		--pi;
		vals[pi] = i;
	}
	bool ok = true;
	rep(i, 9) if (vals[i] != i) ok = false;
	if (ok) {
		cout << 0 << endl;
		return 0;
	}
	int res = 0;
	if (vals[8] == 8) {
		int ti = -1, si = 8;
		rep(j, n) if (vals[j] != j) {
			ti = j;
			break;
		}
		queue<int> que;
		vector<int> dist(n, INF);
		dist[si] = 0;
		que.push(si);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[vi], ndi = di + 1;
			for (int tvi : g[vi]) {
				if (dist[tvi] <= ndi) continue;
				dist[tvi] = ndi;
				if (tvi != ti) que.push(tvi);
			}
		}
		if (dist[ti] == INF) {
			cout << -1 << endl;
			return 0;
		}
		res += dist[ti];
		swap(vals[si], vals[ti]);
	}
	rep(i, n) {
		int si = -1, ti = -1;
		rep(j, n) if (vals[j] == 8) {
			si = j;
			break;
		}
		if (si == 8) {
			bool ok2 = true;
			rep(j, n) if (vals[j] != j) ok2 = false;
			if (ok2) cout << res << endl;
			else cout << -1 << endl;
			return 0;
		}
		rep(j, n) if (vals[j] == si) {
			ti = j;
			break;
		}
		queue<int> que;
		vector<int> dist(n, INF);
		dist[si] = 0;
		que.push(si);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[vi], ndi = di + 1;
			for (int tvi : g[vi]) {
				if (dist[tvi] <= ndi) continue;
				dist[tvi] = ndi;
				if (tvi != ti) que.push(tvi);
			}
		}
		if (dist[ti] == INF) {
			cout << -1 << endl;
			return 0;
		}
		res += dist[ti] + 1;
		swap(vals[si], vals[ti]);
	}
	cout << res << endl;
	return 0;
}
