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

const int INF = (int)(1e9);

int main() {
	int n, ax, ay, bx, by;
	cin >> n >> ax >> ay >> bx >> by;
	vector<string> s(n+2);
	s[0] = s[n+1] = string(n+2, '#');
	rep3(i, 1, n+1) {
		string si;
		cin >> si;
		s[i].push_back('#');
		s[i] += si;
		s[i].push_back('#');
	}
	vector<set<int>> unusedl(2*n+3), unusedr(2*n+3), pornl(2*n+3), pornr(2*n+3);
	rep(i, n+2) rep(j, n+2) {
		int lid = i-j+(n+1), rid = i+j;
		if (s[i][j] == '#') {
			pornl[lid].insert(i);
			pornr[rid].insert(i);
		}
		else {
			unusedl[lid].insert(i);
			unusedr[rid].insert(i);
		}
	}
	vector<vector<int>> dist(n+2, vector<int>(n+2, INF));
	queue<pair<int, int>> que;
	dist[ax][ay] = 0;
	unusedl[ax-ay+n+1].erase(ax);
	unusedr[ax+ay].erase(ax);
	que.emplace(ax, ay);
	while (!que.empty()) {
		auto pi = que.front(); que.pop();
		int vx = pi.first, vy = pi.second, di = dist[vx][vy];
		int lid = vx-vy+n+1, rid = vx + vy;
		{
			auto litr = pornl[lid].lower_bound(vx);
			int lto = *litr, lfr = *prev(litr);
			auto slitr = unusedl[lid].lower_bound(lfr);
			while (slitr!=unusedl[lid].end() && *slitr<lto) {
				int tx = *slitr, ty = -(lid-(n+1)-tx);
				if (dist[tx][ty] > di+1) {
					dist[tx][ty] = di + 1;
					que.emplace(tx, ty);
				}
				slitr = unusedl[lid].erase(slitr);
			}
		}
		{
			auto ritr = pornr[rid].lower_bound(vx);
			int rto = *ritr, rfr = *prev(ritr);
			auto sritr = unusedr[rid].lower_bound(rfr);
			while (sritr!=unusedr[rid].end() && *sritr<rto) {
				int tx = *sritr, ty = rid-tx;
				if (dist[tx][ty] > di+1) {
					dist[tx][ty] = di + 1;
					que.emplace(tx, ty);
				}
				sritr = unusedr[rid].erase(sritr);
			}
		}
	}
	if (dist[bx][by] == INF) cout << -1 << endl;
	else cout << dist[bx][by] << endl;
	return 0;
}
