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
	map<int, int> rank;
	rep(i, n) {
		int sval = 0;
		rep(j, k) sval += max(0, d[i][j]-thre);
		rank[i] = sval;
	}
	vector<vector<int>> g(n);
	vector<int> din(n);
	rep(i, r) {
		g[u[i]].push_back(v[i]);
		din[v[i]]++;
	}
	map<int, deque<int>> tlst;
	function<bool(pair<int,int>,pair<int,int>)> mcomp = [&](pair<int, int> a, pair<int, int> b) -> bool {
		return (a.first>b.first || (a.first==b.first&&rank[a.second]>rank[b.second]));
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(mcomp)> que {mcomp};
	vector<int> dist(n, INF);
	rep(i, n) if (din[i] == 0) {
		dist[i] = 0;
		que.emplace(0, i);
	}
	while (!que.empty()) {
		auto pi = que.top(); que.pop();
		int di = pi.first, vi = pi.second;
		tlst[di].push_back(vi);
		if (g[vi].empty()) continue;
		for (int ti : g[vi]) {
			din[ti]--;
			if (din[ti] == 0) {
				dist[ti] = di+1;
				que.emplace(di+1, ti);
			}
		}
	}
	set<int> workers;
	map<int, int> working;
	int dval = 0;
	rep(i, m) workers.insert(i);
	rep(i, 2000) {
		if (tlst[dval].empty() && working.empty()) {
			for (auto titr=tlst.find(dval); titr!=tlst.end(); ++titr) {
				if (!titr->second.empty()) {
					dval = titr->first;
					break;
				}
				if (next(titr) == tlst.end()) dval = -1;
			}
			if (dval == -1) break;
		}
		vector<pair<int, int>> res;
		for (auto witr=workers.begin(); witr!=workers.end(); ) {
			int wi = *witr;
			if (tlst[dval].empty()) break;
			res.emplace_back(wi+1, tlst[dval].front()+1);
			witr = workers.erase(witr);
			working[wi] = tlst[dval].front();
			tlst[dval].pop_front();
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
			working.erase(fi);
			workers.insert(fi);
		}
	}
	return 0;
}
