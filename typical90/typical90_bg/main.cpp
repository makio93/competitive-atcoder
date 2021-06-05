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

// 自力で解答、WA

const int INF = (int)(1e9);

vector<vector<int>> g;
vector<int> depth, roopid;
vector<bool> visited, finished;
map<int, set<int>> roops;

int dfs(int v, int p=-1, int d=0) {
	if (visited[v]) {
		if (roopid[v] == -1) roopid[v] = v;
		roops[roopid[v]].insert(v);
		depth[v] = min({depth[v], depth[roopid[v]], d});
		depth[roopid[v]] = depth[v];
		return depth[v];
	}
	if (finished[v]) {
		return depth[v] - 1;
	}
	visited[v] = true;
	depth[v] = d;
	bool isroop = false;
	rep(i, (int)(g[v].size())) {
		int t = g[v][i];
		if (t == p) continue;
		depth[v] = min(depth[v], dfs(t, v, depth[v]+1));
		if (roopid[t]!=-1 && visited[t]) {
			roopid[v] = roopid[t];
			depth[v] = min(depth[v], depth[t]);
			depth[roopid[v]] = depth[v];
			roops[roopid[v]].insert(v);
			isroop = true;
		}
	}
	visited[v] = false;
	finished[v] = true;
	return (isroop ? (depth[v]) : (depth[v]-1));
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	g = vector<vector<int>>(n);
	vector<vector<int>> grev(n);
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		g[xi].push_back(yi);
		grev[yi].push_back(xi);
	}
	vector<map<int, int>> ql(n);
	rep(i, q) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		ql[bi][ai] = i;
	}
	vector<bool> ans(q);
	roops = map<int, set<int>>();
	depth = vector<int>(n, INF);
	roopid = vector<int>(n, -1);
	visited = vector<bool>(n);
	finished = vector<bool>(n);
	rep(i, n) if (!finished[i]) dfs(i);
	for (auto ri : roops) {
		int dval = INF;
		for (auto rsi : ri.second) dval = min(dval, depth[rsi]);
		for (auto rsi : ri.second) depth[rsi] = dval;
	}
	//map<int, set<int>> stock;
	map<int, vector<int>> depl;
	rep(i, n) depl[depth[i]].push_back(i);
	queue<int> que;
	vector<pair<bool, map<int, set<int>>>> d(n);
	auto itr = depl.rbegin();
	while (itr != depl.rend()) {
		auto vl = itr->second;
		rep(i, (int)(vl.size())) {
			int v = vl[i];
			if (d[v].first) continue;
			if (roopid[v] != -1) {
				int rid = roopid[v];
				que.push(rid);
				for (int v2 : roops[rid]) d[v2].first = true;
			}
			else {
				que.push(v);
				d[v].first = true;
			}
		}
		while (!que.empty()) {
			int v = que.front(); que.pop();
			auto qli = d[v].second;
			if (roopid[v] != -1) {
				set<int> tl;
				for (int t : roops[v]) {
					for (auto t2 : ql[t]) qli[t2.first].insert(t2.second);
					rep(i, (int)(grev[t].size())) {
						if (roops[v].find(grev[t][i]) != roops[v].end()) continue;
						tl.insert(grev[t][i]);
					}
				}
				for (int t : roops[v]) {
					if (qli.find(t) != qli.end()) {
						for (auto ti : qli[t]) ans[ti] = true;
						qli.erase(t);
					}
				}
				for (int t : tl) {
					if (d[t].first) continue;
					if (roopid[t] == -1) {
						if (!d[t].first) {
							//que.push(t);
							if (!qli.empty()) {
								if (d[t].second.empty()) d[t].second = qli;
								else {
									for (auto qli1 : qli) {
										d[t].second[qli1.first].merge(qli1.second);
										/*
										for (auto itr2=qli1.second.begin(); itr2!=qli1.second.end(); ++itr2) {
											d[t].second[qli1.first].insert(*itr2);
										}
										*/
									}
								}
							}
							//d[t].first = true;
						}
					}
					else {
						int t2 = roopid[t];
						if (!d[t2].first) {
							//que.push(t2);
							if (!qli.empty()) {
								if (d[t2].second.empty()) d[t2].second = qli;
								else {
									for (auto qli1 : qli) {
										d[t2].second[qli1.first].merge(qli1.second);
										/*
										for (auto itr2=qli1.second.begin(); itr2!=qli1.second.end(); ++itr2) {
											d[t2].second[qli1.first].insert(*itr2);
										}
										*/
									}
								}
							}
							//for (int v2 : roops[t2]) d[v2].first = true;
						}
					}
				}
			}
			else {
				for (auto t : ql[v]) qli[t.first].insert(t.second);
				if (qli.find(v) != qli.end()) {
					for (int ti : qli[v]) {
						ans[ti] = true;
					}
					qli.erase(v);
				}
				for (int t : grev[v]) {
					if (roopid[t] == -1) {
						if (!d[t].first) {
							//que.push(t);
							if (!qli.empty()) {
								if (d[t].second.empty()) d[t].second = qli;
								else {
									for (auto qli1 : qli) {
										d[t].second[qli1.first].merge(qli1.second);
										/*
										for (auto itr2=qli1.second.begin(); itr2!=qli1.second.end(); ++itr2) {
											d[t].second[qli1.first].insert(*itr2);
										}
										*/
									}
								}
							}
							//d[t].first = true;
						}
					}
					else {
						int t2 = roopid[t];
						if (!d[t2].first) {
							//que.push(t2);
							if (!qli.empty()) {
								if (d[t2].second.empty()) d[t2].second = qli;
								else {
									for (auto qli1 : qli) {
										d[t2].second[qli1.first].merge(qli1.second);
										/*
										for (auto itr2=qli1.second.begin(); itr2!=qli1.second.end(); ++itr2) {
											d[t2].second[qli1.first].insert(*itr2);
										}
										*/
									}
								}
							}
							//for (int v2 : roops[t2]) d[v2].first = true;
						}
					}
				}
			}
		}
		++itr;
	}
	rep(i, q) if (ans[i]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
