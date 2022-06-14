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

const ll DINF = (ll)(1e18);

int main() {
	int r, c;
	cin >> r >> c;
	vector<vector<int>> a(r, vector<int>(c-1)), b(r-1, vector<int>(c));
	rep(i, r) rep(j, c-1) cin >> a[i][j];
	rep(i, r-1) rep(j, c) cin >> b[i][j];
	priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> que;
	vector<vector<ll>> dist(r, vector<ll>(c, DINF));
	vector<vector<bool>> jumpped(r, vector<bool>(c));
	que.emplace(0LL,pair<int,int>({0,0}));
	dist[0][0] = 0;
	while (!que.empty()) {
		auto p = que.top(); que.pop();
		ll d = p.first;
		int y = p.second.first, x = p.second.second;
		if (dist[y][x] != d) continue;
		const vector<int> dy = { 1, 0, 0 }, dx = { 0, 1, -1 };
		rep(i, 3) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny<0 || ny>=r || nx<0 || nx>=c) continue;
			ll nd = d;
			if (i==0) nd += b[y][x];
			else if (i==1) nd += a[y][x];
			else nd += a[y][x-1];
			if (dist[ny][nx] <= nd) continue;
			que.emplace(nd, pair<int,int>({ny,nx}));
			dist[ny][nx] = nd;
			jumpped[ny][nx] = false;
		}
		if (!jumpped[y][x]) {
			jumpped[y][x] = true;
			rep3(i, 0, y) {
				ll nd = d + (y-i) + 1;
				int ny = i, nx = x;
				if (dist[ny][nx] <= nd) continue;
				que.emplace(nd, pair<int,int>({ny,nx}));
				dist[ny][nx] = nd;
			}
		}
	}
	cout << dist[r-1][c-1] << endl;
	return 0;
}
