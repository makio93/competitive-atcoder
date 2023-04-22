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
	int n, m, k;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui].push_back(vi);
		g[vi].push_back(ui);
	}
	cin >> k;
	vector<int> p(k), d(k);
	rep(i, k) {
		cin >> p[i] >> d[i];
		p[i]--;
	}
	vector<vector<int>> dist(n, vector<int>(n, INF));
	queue<int> que;
	rep(i, n) {
		dist[i][i] = 0;
		que.push(i);
		while (!que.empty()) {
			int vi = que.front(); que.pop();
			int di = dist[i][vi], ndi = di + 1;
			for (const int& ti : g[vi]) {
				if (dist[i][ti] <= ndi) continue;
				dist[i][ti] = ndi;
				que.push(ti);
			}
		}
	}
	unordered_set<int> bst;
	rep(i, n) bst.insert(i);
	rep(i, k) rep(j, n) if (dist[p[i]][j]<d[i] && bst.find(j)!=bst.end()) bst.erase(j);
	bool res = true;
	rep(i, k) {
		bool ok = false;
		rep(j, n) if (dist[p[i]][j]==d[i] && bst.find(j)!=bst.end()) ok = true;
		if (!ok) res = false;
	}
	if (res) {
		string s(n, '0');
		for (const int& vi : bst) s[vi] = '1';
		cout << "Yes" << endl;
		cout << s << endl;
	}
	else cout << "No" << endl;
	return 0;
}
