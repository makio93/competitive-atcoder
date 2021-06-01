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

// 自力AC

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> k(m);
	vector<set<int>> group(n), member(m);
	rep(i, m) {
		cin >> k[i];
		rep(j, k[i]) {
			int ri;
			cin >> ri;
			--ri;
			group[ri].insert(i);
			member[i].insert(ri);
		}
	}
	set<int> gfin;
	vector<int> dist(n, INF);
	queue<int> que;
	que.push(0);
	dist[0] = 0;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int d = dist[v], nd = d + 1;
		auto itr = group[v].begin();
		while (itr != group[v].end()) {
			int gi = *itr;
			if (gfin.find(gi) != gfin.end()) {
				itr = group[v].erase(itr);
				continue;
			}
			auto itr2 = member[gi].begin();
			while (itr2 != member[gi].end()) {
				int mi = *itr2;
				if (dist[mi] > nd) {
					que.push(mi);
					dist[mi] = nd;
				}
				itr2 = member[gi].erase(itr2);
			}
			itr = group[v].erase(itr);
			gfin.insert(gi);
		}
	}
	rep(i, n) {
		if (dist[i] != INF) cout << dist[i] << endl;
		else cout << -1 << endl;
	}
	return 0;
}
