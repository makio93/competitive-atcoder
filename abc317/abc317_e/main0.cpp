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
const vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
const vector<char> dc = { '^', '>', 'v', '<' };

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	queue<tuple<int, int, int>> sque;
	rep(i, h) rep(j, w) if (find(all(dc), a[i][j]) != dc.end()) {
		int cid = find(all(dc), a[i][j]) - dc.begin(), ni = i + di[cid], nj = j + dj[cid];
		if (ni<0 || ni>=h || nj<0 || nj>=w || a[ni][nj]!='.') continue;
		a[ni][nj] = '$';
		sque.emplace(ni, nj, cid);
	}
	while (!sque.empty()) {
		auto [vi, vj, cid] = sque.front(); sque.pop();
		int ni = vi + di[cid], nj = vj + dj[cid];
		if (ni<0 || ni>=h || nj<0 || nj>=w || (a[ni][nj]!='.' && a[ni][nj]!='$')) continue;
		a[ni][nj] = '$';
		sque.emplace(ni, nj, cid);
	}
	int si = -1, sj = -1, gi = -1, gj = -1;
	rep(i, h) rep(j, w) {
		if (a[i][j] == 'S') si = i, sj = j;
		if (a[i][j] == 'G') gi = i, gj = j;
	}
	vector<vector<int>> dist(h, vector<int>(w, INF));
	queue<pair<int, int>> tque;
	dist[si][sj] = 0;
	tque.emplace(si, sj);
	while (!tque.empty()) {
		auto [vi, vj] = tque.front(); tque.pop();
		int vdi = dist[vi][vj], ndi = vdi + 1;
		rep(i2, 4) {
			int ni = vi + di[i2], nj = vj + dj[i2];
			if (ni<0 || ni>=h || nj<0 || nj>=w || (a[ni][nj]!='.' && a[ni][nj]!='G') || dist[ni][nj]<=ndi) continue;
			dist[ni][nj] = ndi;
			tque.emplace(ni, nj);
		}
	}
	if (dist[gi][gj] == INF) cout << -1 << endl;
	else cout << dist[gi][gj] << endl;
	return 0;
}
