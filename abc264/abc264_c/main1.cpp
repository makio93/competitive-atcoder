// 解説AC

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
	int h1, w1, h2, w2;
	cin >> h1 >> w1;
	vector<vector<int>> a(h1, vector<int>(w1));
	rep(i, h1) rep(j, w1) cin >> a[i][j];
	cin >> h2 >> w2;
	vector<vector<int>> b(h2, vector<int>(w2));
	rep(i, h2) rep(j, w2) cin >> b[i][j];
	bool res = false;
	rep(i, 1<<h1) if (__builtin_popcount(i) == h2) {
		rep(j, 1<<w1) if (__builtin_popcount(j) == w2) {
			vector<int> hid, wid;
			rep(i2, h1) if ((i>>i2)&1) hid.push_back(i2);
			rep(j2, w1) if ((j>>j2)&1) wid.push_back(j2);
			bool ok = true;
			rep(i2, h2) {
				rep(j2, w2) if (a[hid[i2]][wid[j2]] != b[i2][j2]) {
					ok = false;
					break;
				}
				if (!ok) break;
			}
			if (ok) {
				res = true;
				break;
			}
		}
		if (res) break;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
