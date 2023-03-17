// 自力AC2

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
	vector<vector<vector<vector<ll>>>> dp(h, vector<vector<vector<ll>>>(w, vector<vector<ll>>(2, vector<ll>(4, LINF))));
	rep(i, h) rep(j, w) rep(k, 2) {
		if (i==0 && j==0) {
			if (a[0][0] == (char)('0'+k)) {
				dp[i][j][k][0] = 0;
				dp[i][j][k][3] = (ll)r[i] + c[j];
			}
			else {
				dp[i][j][k][2] = r[i];
				dp[i][j][k][1] = c[j];
			}
			continue;
		}
		else {
			if (j-1 >= 0) {
				if (a[i][j] == (char)('0'+k)) {
					if (a[i][j-1] == a[i][j]) {
						dp[i][j][k][0] = min({ LINF, dp[i][j][k][0], dp[i][j-1][k][0] });
						dp[i][j][k][3] = min({ LINF, dp[i][j][k][3], dp[i][j-1][k][3]+c[j] });
					}
					else {
						dp[i][j][k][0] = min({ LINF, dp[i][j][k][0], dp[i][j-1][k][1] });
						dp[i][j][k][3] = min({ LINF, dp[i][j][k][3], dp[i][j-1][k][2]+c[j] });
					}
				}
				else {
					if (a[i][j-1] == a[i][j]) {
						dp[i][j][k][1] = min({ LINF, dp[i][j][k][1], dp[i][j-1][k][1]+c[j] });
						dp[i][j][k][2] = min({ LINF, dp[i][j][k][2], dp[i][j-1][k][2] });
					}
					else {
						dp[i][j][k][1] = min({ LINF, dp[i][j][k][1], dp[i][j-1][k][0]+c[j] });
						dp[i][j][k][2] = min({ LINF, dp[i][j][k][2], dp[i][j-1][k][3] });
					}
				}
			}
			if (i-1 >= 0) {
				if (a[i][j] == (char)('0'+k)) {
					if (a[i-1][j] == a[i][j]) {
						dp[i][j][k][0] = min({ LINF, dp[i][j][k][0], dp[i-1][j][k][0] });
						dp[i][j][k][3] = min({ LINF, dp[i][j][k][3], dp[i-1][j][k][3]+r[i] });
					}
					else {
						dp[i][j][k][0] = min({ LINF, dp[i][j][k][0], dp[i-1][j][k][2] });
						dp[i][j][k][3] = min({ LINF, dp[i][j][k][3], dp[i-1][j][k][1]+r[i] });
					}
				}
				else {
					if (a[i-1][j] == a[i][j]) {
						dp[i][j][k][2] = min({ LINF, dp[i][j][k][2], dp[i-1][j][k][2]+r[i] });
						dp[i][j][k][1] = min({ LINF, dp[i][j][k][1], dp[i-1][j][k][1] });
					}
					else {
						dp[i][j][k][2] = min({ LINF, dp[i][j][k][2], dp[i-1][j][k][0]+r[i] });
						dp[i][j][k][1] = min({ LINF, dp[i][j][k][1], dp[i-1][j][k][3] });
					}
				}
			}
		}
	}
	ll res = LINF;
	rep(i, 2) rep(j, 4) res = min(res, dp[h-1][w-1][i][j]);
	cout << res << endl;
	return 0;
}
