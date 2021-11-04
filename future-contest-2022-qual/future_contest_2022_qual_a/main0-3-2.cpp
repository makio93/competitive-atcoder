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
	vector<vector<int>> s(m, vector<int>(k, 40));
	vector<int> scnt(m);
	set<int> workers;
	rep(i, m) workers.insert(i);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tasks;
	map<int, int> working, sches;
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
			int tid = tasks.top().second;
			pair<int, int> smval = { INF, -1 };
			for (auto pi : workers) {
				int sum = 0;
				rep(j, k) sum += max(0, d[tid][j]-s[pi][j]);
				smval = min(smval, { sum, pi });
			}
			int sid = smval.second, tval = (smval.first == 0) ? 1 : max(1, smval.first);
			res.emplace_back(sid+1, tid+1);
			working[sid] = tid;
			sches[sid] = i+tval-1;
			workers.erase(sid);
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
			int tval = sches[fi], sub = tval - i;
			vector<pair<int, int>> dlst(k);
			rep(j, k) dlst[j] = { d[vi][j], j };
			sort(dlst.rbegin(), dlst.rend());
			int aval = abs(sub) / k, bval = abs(sub) % k;
			auto td = d[vi];
			rep(j, k) {
				int add = aval + ((j<=bval) ? 1 : 0);
				if (sub < 0) add *= -1;
				td[dlst[j].second] += add;
				if (add == 0) td[dlst[j].second] = (td[dlst[j].second]*8+3) / 5;
			}
			rep(j, k) s[fi][j] = ((ll)s[fi][j] * scnt[fi] + td[j] + (scnt[fi]+1)/2) / (scnt[fi]+1);
			scnt[fi]++;
			working.erase(fi);
			sches.erase(fi);
			workers.insert(fi);
		}
	}
	return 0;
}
