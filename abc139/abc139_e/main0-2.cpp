// バチャ,自力AC2

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
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n-1));
	rep(i, n) rep(j, n-1) {
		cin >> a[i][j];
		a[i][j]--;
	}
	vector<pair<int, int>> vlst;
	rep(i, n) rep3(j, i+1, n) vlst.emplace_back(i, j);
	int m = vlst.size();
	map<pair<int, int>, int> vids;
	rep(i, m) vids[vlst[i]] = i;
	vector<vector<int>> g(m);
	vector<int> din(m);
	rep(i, n) rep(j, n-2) {
		pair<int, int> li = { i, a[i][j] }, ri = { i, a[i][j+1] };
		if (li.first > li.second) swap(li.first, li.second);
		if (ri.first > ri.second) swap(ri.first, ri.second);
		int vi = vids[li], ti = vids[ri];
		g[vi].push_back(ti);
		din[ti]++;
	}
	vector<int> dist(m, -INF);
	queue<int> que;
	rep(i, m) if (din[i] == 0) {
		dist[i] = 1;
		que.push(i);
	}
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dist[vi], ndi = di + 1;
		for (const int& ti : g[vi]) if (din[ti] > 0) {
			if (dist[ti] < ndi) dist[ti] = ndi;
			din[ti]--;
			if (din[ti] == 0) que.push(ti);
		}
	}
	if ((int)(count(all(dist), -INF)) > 0) cout << -1 << endl;
	else {
		int res = *max_element(all(dist));
		cout << res << endl;
	}
	return 0;
}
