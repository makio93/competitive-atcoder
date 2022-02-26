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

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	--sx; --sy; --gx; --gy;
	unordered_map<int, set<int>> xlst, ylst;
	rep(i, n) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		xlst[xi].insert(yi);
		ylst[yi].insert(xi);
	}
	queue<pair<int, int>> que;
	map<pair<int, int>, int> dist;
	dist[{sx, sy}] = 0;
	que.emplace(sx, sy);
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int xi = pi.first, yi = pi.second, di = dist[{xi, yi}];
		if (xlst.find(xi) != xlst.end()) {
			auto xitr = xlst[xi].upper_bound(yi);
			if (xitr != xlst[xi].end()) {
				int nxi = xi, nyi = *xitr - 1;
				if (dist.find({nxi, nyi})==dist.end() || dist[{nxi, nyi}]>di+1) {
					dist[{nxi, nyi}] = di + 1;
					que.emplace(nxi, nyi);
				}
			}
			if (xitr != xlst[xi].begin()) {
				--xitr;
				int nxi = xi, nyi = *xitr + 1;
				if (dist.find({nxi, nyi})==dist.end() || dist[{nxi, nyi}]>di+1) {
					dist[{nxi, nyi}] = di + 1;
					que.emplace(nxi, nyi);
				}
			}
		}
		if (ylst.find(yi) != ylst.end()) {
			auto yitr = ylst[yi].upper_bound(xi);
			if (yitr != ylst[yi].end()) {
				int nxi = *yitr - 1, nyi = yi;
				if (dist.find({nxi, nyi})==dist.end() || dist[{nxi, nyi}]>di+1) {
					dist[{nxi, nyi}] = di + 1;
					que.emplace(nxi, nyi);
				}
			}
			if (yitr != ylst[yi].begin()) {
				--yitr;
				int nxi = *yitr + 1, nyi = yi;
				if (dist.find({nxi, nyi})==dist.end() || dist[{nxi, nyi}]>di+1) {
					dist[{nxi, nyi}] = di + 1;
					que.emplace(nxi, nyi);
				}
			}
		}
	}
	if (dist.find({gx, gy}) != dist.end()) cout << dist[{gx, gy}] << endl;
	else cout << -1 << endl;
	return 0;
}
