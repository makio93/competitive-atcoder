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
	vector<vector<int>> s(n);
	rep(i, n) {
		int ai;
		cin >> ai;
		rep(j, ai) {
			int sj;
			cin >> sj;
			--sj;
			s[i].push_back(sj);
		}
	}
	vector<unordered_set<int>> svals(n), sids(m);
	rep(i, n) for (const int& vi : s[i]) {
		svals[i].insert(vi);
		sids[vi].insert(i);
	}
	vector<int> dist(m, INF);
	queue<int> que;
	dist[0] = 0;
	for (const int& si : sids[0]) {
		for (const int& vi : svals[si]) if (vi != 0) {
			if (dist[vi] == INF) {
				dist[vi] = 0;
				que.push(vi);
			}
			sids[vi].erase(si);
		}
		svals[si].clear();
	}
	sids[0].clear();
	while (!que.empty()) {
		int vi = que.front(); que.pop();
		int di = dist[vi], ndi = di + 1;
		for (const int& si : sids[vi]) {
			for (const int& ti : svals[si]) if (ti != vi) {
				if (dist[ti] == INF) {
					dist[ti] = ndi;
					que.push(ti);
				}
				sids[ti].erase(si);
			}
			svals[si].clear();
		}
		sids[vi].clear();
	}
	if (dist[m-1] == INF) cout << -1 << endl;
	else cout << dist[m-1] << endl;
	return 0;
}
