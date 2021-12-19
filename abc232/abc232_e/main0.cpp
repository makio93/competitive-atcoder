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

// 本番実装,未完成

using mint = modint998244353;

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	--x1; --y1; --x2; --y2;
	vector<int> xids, yids;
	xids.push_back(-1);
	xids.push_back(x1);
	xids.push_back(x2);
	xids.push_back(w);
	yids.push_back(-1);
	yids.push_back(y1);
	yids.push_back(y2);
	yids.push_back(h);
	sort(all(xids));
	xids.erase(unique(all(xids)), xids.end());
	sort(all(yids));
	yids.erase(unique(all(yids)), yids.end());
	int xlen = xids.size() - 1, ylen = yids.size() - 1;
	vector<vector<mint>> dist(ylen*2, vector<mint>(xlen*2));
	rep(i, ylen) rep(j, xlen) if (i==y1 && j==x1) dist[i*2][j*2] = 1;
	rep(i, k) {
		auto ndist = dist;
		// ここで未完成
	}
	return 0;
}
