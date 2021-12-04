#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番TLE

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
	vector<unordered_map<ll, int>> dist(10);
	int res = INF, rcnt = 0;
	function<bool(int)> check = [&](ll val) -> bool {
		return (val!=0LL && val%(ll)(m)==(ll)(r));
	};
	priority_queue<tuple<int, int, ll>, vector<tuple<int, int, ll>>, greater<tuple<int, int, ll>>> que;
	for (ll i=1; i<10; ++i) {
		int d = costs[0][(int)i] + 1;
		if (d >= res) continue;
		dist[(int)i][i] = d;
		if (check(i)) res = min(res, d);
		else {
			que.emplace(d, (int)i, i);
			++rcnt;
		}
	}
	while (!que.empty() && rcnt<=m*20) {
		auto [d, p, v] = que.top(); que.pop();
		if (dist[p][v] != d) continue;
		if (d >= res) continue;
		if (v >= (ll)(1e17)) continue;
		rep(i, 10) {
			int dd = costs[p][i] + 1, nd = d + dd;
			if (nd >= res) continue;
			ll nv = v * 10 + i;
			if (dist[i].find(nv)!=dist[i].end() && dist[i][nv]<=nd) continue;
			dist[i][nv] = nd;
			if (check(nv)) res = min(res, nd);
			else {
				que.emplace(nd, i, nv);
				++rcnt;
			}
		}
	}
	cout << res << endl;
	return 0;
}
