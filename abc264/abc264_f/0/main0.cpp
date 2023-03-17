// 自力AC

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

const ll LINF = (ll)(1e18);

int main() {
	int h, w;
	cin >> h >> w;
	vector<int> r(h), c(w);
	rep(i, h) cin >> r[i];
	rep(i, w) cin >> c[i];
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	vector<vector<vector<ll>>> wdp(h, vector<vector<ll>>(w, vector<ll>(4, LINF))), bdp(h, vector<vector<ll>>(w, vector<ll>(4, LINF)));
	rep(i, h) rep(j, w) {
		if (i==0 && j==0) {
			if (a[0][0] == '0') {
				wdp[i][j][0] = 0;
				wdp[i][j][3] = (ll)r[i] + c[j];
			}
			else {
				wdp[i][j][2] = r[i];
				wdp[i][j][1] = c[j];
			}
			continue;
		}
		if (j-1 >= 0) {
			if (a[i][j] == '0') {
				if (a[i][j-1] == '0') {
					wdp[i][j][0] = min({ LINF, wdp[i][j][0], wdp[i][j-1][0] });
					wdp[i][j][3] = min({ LINF, wdp[i][j][3], wdp[i][j-1][3]+c[j] });
				}
				else {
					wdp[i][j][0] = min({ LINF, wdp[i][j][0], wdp[i][j-1][1] });
					wdp[i][j][3] = min({ LINF, wdp[i][j][3], wdp[i][j-1][2]+c[j] });
				}
			}
			else {
				if (a[i][j-1] == '1') {
					wdp[i][j][1] = min({ LINF, wdp[i][j][1], wdp[i][j-1][1]+c[j] });
					wdp[i][j][2] = min({ LINF, wdp[i][j][2], wdp[i][j-1][2] });
				}
				else {
					wdp[i][j][1] = min({ LINF, wdp[i][j][1], wdp[i][j-1][0]+c[j] });
					wdp[i][j][2] = min({ LINF, wdp[i][j][2], wdp[i][j-1][3] });
				}
			}
		}
		if (i-1 >= 0) {
			if (a[i][j] == '0') {
				if (a[i-1][j] == '0') {
					wdp[i][j][0] = min({ LINF, wdp[i][j][0], wdp[i-1][j][0] });
					wdp[i][j][3] = min({ LINF, wdp[i][j][3], wdp[i-1][j][3]+r[i] });
				}
				else {
					wdp[i][j][0] = min({ LINF, wdp[i][j][0], wdp[i-1][j][2] });
					wdp[i][j][3] = min({ LINF, wdp[i][j][3], wdp[i-1][j][1]+r[i] });
				}
			}
			else {
				if (a[i-1][j] == '1') {
					wdp[i][j][2] = min({ LINF, wdp[i][j][2], wdp[i-1][j][2]+r[i] });
					wdp[i][j][1] = min({ LINF, wdp[i][j][1], wdp[i-1][j][1] });
				}
				else {
					wdp[i][j][2] = min({ LINF, wdp[i][j][2], wdp[i-1][j][0]+r[i] });
					wdp[i][j][1] = min({ LINF, wdp[i][j][1], wdp[i-1][j][3] });
				}
			}
		}
	}
	rep(i, h) rep(j, w) {
		if (a[i][j] == '0') a[i][j] = '1';
		else a[i][j] = '0';
	}
	rep(i, h) rep(j, w) {
		if (i==0 && j==0) {
			if (a[0][0] == '0') {
				bdp[i][j][0] = 0;
				bdp[i][j][3] = (ll)r[i] + c[j];
			}
			else {
				bdp[i][j][2] = r[i];
				bdp[i][j][1] = c[j];
			}
			continue;
		}
		if (j-1 >= 0) {
			if (a[i][j] == '0') {
				if (a[i][j-1] == '0') {
					bdp[i][j][0] = min({ LINF, bdp[i][j][0], bdp[i][j-1][0] });
					bdp[i][j][3] = min({ LINF, bdp[i][j][3], bdp[i][j-1][3]+c[j] });
				}
				else {
					bdp[i][j][0] = min({ LINF, bdp[i][j][0], bdp[i][j-1][1] });
					bdp[i][j][3] = min({ LINF, bdp[i][j][3], bdp[i][j-1][2]+c[j] });
				}
			}
			else {
				if (a[i][j-1] == '1') {
					bdp[i][j][1] = min({ LINF, bdp[i][j][1], bdp[i][j-1][1]+c[j] });
					bdp[i][j][2] = min({ LINF, bdp[i][j][2], bdp[i][j-1][2] });
				}
				else {
					bdp[i][j][1] = min({ LINF, bdp[i][j][1], bdp[i][j-1][0]+c[j] });
					bdp[i][j][2] = min({ LINF, bdp[i][j][2], bdp[i][j-1][3] });
				}
			}
		}
		if (i-1 >= 0) {
			if (a[i][j] == '0') {
				if (a[i-1][j] == '0') {
					bdp[i][j][0] = min({ LINF, bdp[i][j][0], bdp[i-1][j][0] });
					bdp[i][j][3] = min({ LINF, bdp[i][j][3], bdp[i-1][j][3]+r[i] });
				}
				else {
					bdp[i][j][0] = min({ LINF, bdp[i][j][0], bdp[i-1][j][2] });
					bdp[i][j][3] = min({ LINF, bdp[i][j][3], bdp[i-1][j][1]+r[i] });
				}
			}
			else {
				if (a[i-1][j] == '1') {
					bdp[i][j][2] = min({ LINF, bdp[i][j][2], bdp[i-1][j][2]+r[i] });
					bdp[i][j][1] = min({ LINF, bdp[i][j][1], bdp[i-1][j][1] });
				}
				else {
					bdp[i][j][2] = min({ LINF, bdp[i][j][2], bdp[i-1][j][0]+r[i] });
					bdp[i][j][1] = min({ LINF, bdp[i][j][1], bdp[i-1][j][3] });
				}
			}
		}
	}
	ll res = LINF;
	rep(i, 4) res = min(res, wdp[h-1][w-1][i]);
	rep(i, 4) res = min(res, bdp[h-1][w-1][i]);
	cout << res << endl;
	return 0;
}
