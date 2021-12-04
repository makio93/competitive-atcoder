#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番AC

const int INF = (int)(1e9);

const vector<vector<int>> costs = { 
	{ 0, 1, 2, 3, 2, 3, 4, 3, 4, 5 }, 
	{ 1, 0, 1, 2, 1, 2, 3, 2, 3, 4 }, 
	{ 2, 1, 0, 1, 2, 1, 2, 3, 2, 3 },
	{ 3, 2, 1, 0, 3, 2, 1, 4, 3, 2 }, 
	{ 2, 1, 2, 3, 0, 1, 2, 1, 2, 3 },
	{ 3, 2, 1, 2, 1, 0, 1, 2, 1, 2 },
	{ 4, 3, 2, 1, 2, 1, 0, 3, 2, 1 },
	{ 3, 2, 3, 4, 1, 2, 3, 0, 1, 2 },
	{ 4, 3, 2, 3, 2, 1, 2, 1, 0, 1 },
	{ 5, 4, 3, 2, 3, 2, 1, 2, 1, 0 }
};

int main() {
	int m, r;
	cin >> m >> r;
	vector<vector<int>> dist(m, vector<int>(10, INF));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
	int rval = INF;
	rep3(i, 1, 10) {
		int d = costs[0][i] + 1;
		dist[i%m][i] = d;
		if (i%m == r) rval = min(rval, d);
		else que.emplace(d, i%m, i);
	}
	while (!que.empty()) {
		auto [d, v, p] = que.top(); que.pop();
		if (dist[v][p] != d) continue;
		if (d >= rval) continue;
		rep(i, 10) {
			int nv = (v * 10 + i) % m, np = i, nd = d + costs[p][np] + 1;
			if (nd >= rval) continue;
			if (dist[nv][np] <= nd) continue;
			dist[nv][np] = min(dist[nv][np], nd);
			if (nv == r) rval = min(rval, nd);
			else que.emplace(nd, nv, np);
		}
	}
	cout << rval << endl;
	return 0;
}
