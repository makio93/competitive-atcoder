// 解説AC

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

const int INF = (int)(1.1e9);

struct Points {
	vector<pair<int, int>> plst;
	void add(const pair<int, int>& p) { plst.push_back(p); }
	void add(int x, int y) { add(make_pair(x, y)); }
	void init() { sort(all(plst)); }
	int operator()(const pair<int, int>& p) const {
		auto itr = lower_bound(all(plst), p);
		if (itr!=plst.end() && p==*itr) return distance(plst.begin(), itr);
		else return -1;
	}
	int operator()(int x, int y) const { return operator()(make_pair(x, y)); }
	pair<int, int> operator[](int id) const { return plst[id]; }
	int size() const { return plst.size(); }
};

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	--sx; --sy; --gx; --gy;
	unordered_map<int, set<int>> xys, yxs;
	Points stones;
	stones.add(sx, sy);
	stones.add(gx, gy);
	rep(i, n) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		xys[xi].insert(yi);
		yxs[yi].insert(xi);
		const vector<int> dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };
		rep(i2, 4) {
			int nx = xi + dx[i2], ny = yi + dy[i2];
			if (nx<0 || nx>=h || ny<0 || ny>=w) continue;
			stones.add(nx, ny);
		}
	}
	stones.init();
	int m = stones.size();
	vector<int> dist(m, INF);
	queue<int> que;
	auto push = [&](int xi, int yi, int di) {
		int id = stones(xi, yi);
		if (id==-1 || dist[id]!=INF) return;
		dist[id] = di;
		que.push(id);
	};
	push(sx, sy, 0);
	while (!que.empty()) {
		auto [xi, yi] = stones[que.front()]; que.pop();
		int di = dist[stones(xi, yi)];
		{
			auto itr = yxs[yi].lower_bound(xi);
			if (itr != yxs[yi].end()) push(*itr-1, yi, di+1);
			if (itr != yxs[yi].begin()) {
				--itr;
				push(*itr+1, yi, di+1);
			}
		}
		{
			auto itr = xys[xi].lower_bound(yi);
			if (itr != xys[xi].end()) push(xi, *itr-1, di+1);
			if (itr != xys[xi].begin()) {
				--itr;
				push(xi, *itr+1, di+1);
			}
		}
	}
	if (dist[stones(gx, gy)] == INF) cout << -1 << endl;
	else cout << dist[stones(gx, gy)] << endl;
	return 0;
}
