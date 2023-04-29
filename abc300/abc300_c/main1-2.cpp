// 解説AC2

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
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	int n = min(h, w);
	vector<int> s(n);
	rep(i, h) rep(j, w) if (c[i][j] == '#') {
		int li = INF, ri = -1, ui = INF, di = -1;
		queue<pair<int, int>> que;
		que.emplace(i, j);
		li = min(li, j), ri = max(ri, j), ui = min(ui, i), di = max(di, i);
		c[i][j] = '.';
		while (!que.empty()) {
			auto [yi, xi] = que.front(); que.pop();
			rep3(i2, -1, 2) rep3(j2, -1, 2) if (i2!=0 || j2!=0) {
				int nyi = yi + i2, nxi = xi + j2;
				if (nyi<0 || nyi>=h || nxi<0 || nxi>=w || c[nyi][nxi]!='#') continue;
				li = min(li, nxi), ri = max(ri, nxi), ui = min(ui, nyi), di = max(di, nyi);
				que.emplace(nyi, nxi);
				c[nyi][nxi] = '.';
			}
		}
		s[(di-ui)/2-1]++;
	}
	rep(i, n) cout << s[i] << (i<n-1?' ':'\n');
	return 0;
}
