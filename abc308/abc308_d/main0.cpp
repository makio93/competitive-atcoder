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
const string tar = "snuke";
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<vector<int>> dists(h, vector<int>(w, INF));
	queue<pair<int, int>> que;
	if (s[0][0] == tar[0]) {
		que.emplace(0, 0);
		dists[0][0] = 0;
	}
	while (!que.empty()) {
		auto [yi, xi] = que.front(); que.pop();
		int di = dists[yi][xi], ndi = di + 1, tid = ndi % 5;
		rep(i2, 4) {
			int nyi = yi + dy[i2], nxi = xi + dx[i2];
			if (nyi<0 || nyi>=h || nxi<0 || nxi>=w || dists[nyi][nxi]<=ndi || s[nyi][nxi]!=tar[tid]) continue;
			dists[nyi][nxi] = ndi;
			que.emplace(nyi, nxi);
		}
	}
	if (dists[h-1][w-1] == INF) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
