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

const string tar = "URDL";
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	rep(i, h) cin >> g[i];
	int y = 0, x = 0;
	while (g[y][x] != '.') {
		int di = tar.find(g[y][x]);
		int ny = y + dy[di], nx = x + dx[di];
		if (ny<0 || ny>=h || nx<0 || nx>=w) break;
		g[y][x] = '.';
		y = ny; x = nx;
	}
	if (g[y][x] == '.') cout << -1 << endl;
	else cout << (y+1) << ' ' << (x+1) << endl;
	return 0;
}
