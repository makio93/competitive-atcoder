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
int thre = 30;
clock_t start_t = clock();

int main() {
	int n, m, k, r;
	cin >> n >> m >> k >> r;
	int mmval = (n+(m/2)) / m;
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
	random_device seed_gen;
	default_random_engine engine(seed_gen());
	normal_distribution<> randnorm(0.0, 1.0);
	uniform_real_distribution<> randdoub(20.0, 60.0);
	vector<vector<int>> s(m, vector<int>(k));
	rep(i, m) {
		vector<double> ps(k);
		rep(j, k) ps[j] = abs(randnorm(engine));
		double ksum = 0.0;
		rep(j, k) ksum += ps[j] * ps[j];
		ksum = sqrt(ksum);
		vector<double> q(k);
		rep(j, k) q[j] = randdoub(engine) / ksum;
		rep(j, k) s[i][j] = (int)round(q[j]*ps[j]);
	}
	vector<vector<pair<int, int>>> slogs(m);
	set<int> workers;
	rep(i, m) workers.insert(i);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tasks;
	map<int, int> working, sches, fsches;
	set<pair<int, int>> que;
	vector<int> dist(n, INF);
	rep(i, n) if (din[i] == 0) {
		dist[i] = 0;
		que.emplace(0, i);
		tasks.emplace(0, i);
	}
	rep(i, 2000) {
		vector<pair<int, int>> res;
		vector<pair<int, int>> contasks;
		while (!tasks.empty()) {
			contasks.push_back(tasks.top());
			tasks.pop();
		}
		int ttlen = contasks.size(), tglen = m + ttlen + 2;
		mcf_graph<int, int> tg(tglen);
		rep(j1, m) rep(j2, ttlen) {
			int sadd = 0, tcost = 0, ttid = contasks[j2].second;
			if (working.find(j1) != working.end()) sadd += fsches[j1] - i;
			rep(ji, k) tcost += max(0, d[ttid][ji]-s[j1][ji]);
			tcost = max(1, tcost) + sadd;
			tg.add_edge(j1, m+j2, 1, tcost);
		}
		rep(j, m) tg.add_edge(m+ttlen, j, 1, 0);
		rep(j, ttlen) tg.add_edge(m+j, m+ttlen+1, 1, 0);
		tg.flow(m+ttlen, m+ttlen+1, (int)(workers.size()));
		unordered_set<int> usworkers, ustasks;
		rep(j, m*ttlen) {
			if (usworkers.find(tg.get_edge(j).from) != usworkers.end()) continue;
			if (workers.find(tg.get_edge(j).from) != workers.end()) {
				if (tg.get_edge(j).flow > 0) {
					int sid = tg.get_edge(j).from, tid = contasks[tg.get_edge(j).to-m].second;
					res.emplace_back(sid+1, tid+1);
					usworkers.insert(sid);
					ustasks.insert(tid);
					working[sid] = tid;
					sches[sid] = i;
					fsches[sid] = i + tg.get_edge(j).cost;
				}
			}
		}
		for (int sid : usworkers) workers.erase(sid);
		for (auto tpi : contasks) if (ustasks.find(tpi.second) == ustasks.end()) tasks.emplace(tpi);
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
		rep(j, nlen) {
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
			int tval = i - sches[fi] + 1;
			slogs[fi].emplace_back(vi, tval);
			pair<int, vector<int>> mlst = { 0, s[fi] };
			for (auto pi : slogs[fi]) rep(j2, k) mlst.first += max(0, d[pi.first][j2]-s[fi][j2]);
			clock_t now_t = clock();
			if ((now_t-start_t)/(double)(CLOCKS_PER_SEC) <= 2.8*i/2000) {
				int ni = min(mmval, (int)(slogs[fi].size()));
				int elen = max(1, (int)round(20.0*(mmval-ni)/(double)mmval*(mmval-ni)/(double)mmval));
				int elen2 = max(1, (int)round((double)k*(mmval-ni)/(double)mmval*(mmval-ni)/(double)mmval));
				uniform_int_distribution<> randint(0, (elen*2+1)*k-1);
				rep(j1, 200*(int)(slogs[fi].size())) {
					now_t = clock();
					if ((now_t-start_t)/(double)(CLOCKS_PER_SEC) > 2.8*i/2000) break;
					int nsum = 0;
					vector<int> ns = mlst.second;
					rep(j2, elen2) {
						int rval = randint(engine), add = rval/k - elen, tki = rval % k;
						ns[tki] += add;
					}
					for (auto pi : slogs[fi]) {
						int tval1 = 0;
						rep(j2, k) tval1 += max(0, d[pi.first][j2]-ns[j2]);
						if (tval1 == 0) tval1 = 1;
						else tval1 = max(1, tval1);
						nsum += abs(tval1-pi.second);
					}
					mlst = min(mlst, { nsum, ns });
				}
			}
			swap(mlst.second, s[fi]);
			working.erase(fi);
			sches.erase(fi);
			workers.insert(fi);
		}
	}
	return 0;
}
