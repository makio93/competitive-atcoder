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
	vector<int> h(3), w(3);
	rep(i, 3) cin >> h[i];
	rep(i, 3) cin >> w[i];
	vector<vector<int>> c(3, vector<int>(3));
	int res = 0;
	rep3(i1, 1, 31) {
		c[0][0] = i1;
		rep3(j1, 1, 31) {
			c[0][1] = j1;
			rep3(i2, 1, 31) {
				c[1][0] = i2;
				rep3(j2, 1, 31) {
					c[1][1] = j2;
					rep(i3, 2) c[i3][2] = h[i3] - c[i3][0] - c[i3][1];
					rep(i3, 3) c[2][i3] = w[i3] - c[0][i3] - c[1][i3];
					if (c[2][2] != h[2]-c[2][0]-c[2][1]) continue;
					bool ok = true;
					rep(i3, 3) rep(j3, 3) if (c[i3][j3] <= 0) ok = false;
					if (ok) ++res;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
