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

const int INF = (int)(1e9);
int thre = 30;

int main() {
	int n, m, k, r;
	cin >> n >> m >> k >> r;
	vector<vector<int>> d(n, vector<int>(k));
	rep(i, n) rep(j, k) cin >> d[i][j];
	vector<int> u(r), v(r);
	rep(i, r) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	vector<vector<int>> g(n);
	vector<int> din(n);
	rep(i, r) {
		g[u[i]].push_back(v[i]);
		din[v[i]]++;
	}
	set<int> workers;
	rep(i, m) workers.insert(i);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tasks;
	map<int, int> working;
	set<pair<int, int>> que;
	vector<int> dist(n, INF);
	rep(i, n) if (din[i] == 0) {
		dist[i] = 0;
		que.emplace(0, i);
		tasks.emplace(0, i);
	}
	rep(i, 2000) {
		vector<pair<int, int>> res;
		while (!workers.empty() && !tasks.empty()) {
			res.emplace_back((*workers.begin())+1, tasks.top().second+1);
			working[*workers.begin()] = tasks.top().second;
			workers.erase(workers.begin());
			tasks.pop();
		}
		int rlen = res.size();
		if (rlen == 0) cout << rlen << '\n';
		else {
			cout << rlen << ' ';
			rep(j, rlen) printf("%d %d%c", res[j].first, res[j].second, (j<rlen-1?' ':'\n'));
		}
		flush(cout);
		int nlen;
		cin >> nlen;
		if (nlen == -1) break;
		rep(i, nlen) {
			int fi;
			cin >> fi;
			--fi;
			int vi = working[fi], di = dist[vi];
			que.erase({di, vi});
			for (int ti : g[vi]) {
				din[ti]--;
				if (din[ti] == 0) {
					dist[ti] = di + 1;
					que.emplace(di+1, ti);
					tasks.emplace(di+1, ti);
				}
			}
			working.erase(fi);
			workers.insert(fi);
		}
	}
	return 0;
}
