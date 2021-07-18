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

// 本番中、誤答

const int INF = (int)(1e9);
const ll LINF = (ll)(1e18);

int main() {
	int h, w, c;
	cin >> h >> w >> c;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	pair<ll, pair<int, int>> mval = { LINF, { -1, -1 } };
	vector<vector<int>> dist(h, vector<int>(w, INF));
	queue<pair<int, int>> que;
	set<pair<ll, int>> pcnt;
	que.emplace(0, 0);
	dist[0][0] = 0;
	pcnt.emplace(a[0][0], 0);
	while (!que.empty()) {
		auto p = que.front(); que.pop();
		int y = p.first, x = p.second;
		int d = dist[y][x], nd = d + 1;
		const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
		rep(i1, 4) {
			int ny = y + dy[i1], nx = x + dx[i1];
			if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
			if (dist[ny][nx] <= nd) continue;
			que.emplace(ny, nx);
			dist[ny][nx] = nd;
			pair<ll, int> tval = (*pcnt.begin());
			ll tval2 = (ll)a[ny][nx] - (ll)nd * c;
			int y1 = tval.second / w, x1 = tval.second % w;
			ll mval2 = (ll)a[y1][x1] + a[ny][nx] + (ll)(abs(y1-ny)+abs(x1-nx)) * c;
			mval = min(mval, { mval2, { tval.second, ny*w+nx } });
			pcnt.emplace(tval2, ny*w+nx);
		}
	}
	int y1 = mval.second.first / w, x1 = mval.second.first % w;
	int y2 = mval.second.second / w, x2 = mval.second.second % w;
	ll res = (ll)a[y1][x1] + a[y2][x2] + (ll)(abs(y1-y2) + abs(x1-x2)) * c;
	cout << res << endl;
	return 0;
}
