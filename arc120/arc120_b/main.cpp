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

using mint = modint998244353;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	mint res = 1;
	const vector<char> tar = { 'R', 'B' };
	rep(i, w) {
		int y = 0, x = i;
		vector<bool> ok(2, true);
		int dy = 1, dx = -1;
		while (y>=0 && y<h && x>=0 &&x<w) {
			rep(j, 2) if (s[y][x] == tar[j]) ok[1-j] = false;
			y += dy; x += dx;
		}
		int cnt = 0;
		rep(j, 2) if (ok[j]) ++cnt;
		res *= cnt;
	}
	rep3(i, 1, h) {
		int y = i, x = w-1;
		vector<bool> ok(2, true);
		int dy = 1, dx = -1;
		while (y>=0 && y<h && x>=0 &&x<w) {
			rep(j, 2) if (s[y][x] == tar[j]) ok[1-j] = false;
			y += dy; x += dx;
		}
		int cnt = 0;
		rep(j, 2) if (ok[j]) ++cnt;
		res *= cnt;
	}
	cout << res.val() << endl;
	return 0;
}
