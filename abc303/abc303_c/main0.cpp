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
const string tar = "RLUD";
const vector<int> dy = { 0, 0, 1, -1 }, dx = { 1, -1, 0, 0 };

int main() {
	int n, m, h, k;
	string s;
	cin >> n >> m >> h >> k >> s;
	set<pair<int, int>> xy;
	rep(i, m) {
		int xi, yi;
		cin >> xi >> yi;
		xy.emplace(xi, yi);
	}
	int xi = 0, yi = 0;
	bool ok = true;
	rep(i, n) {
		int di = tar.find(s[i]);
		xi += dx[di], yi += dy[di];
		--h;
		if (h < 0) {
			ok = false;
			break;
		}
		if (xy.find({xi, yi}) != xy.end() && h < k) {
			xy.erase({xi, yi});
			h = k;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
