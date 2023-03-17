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

const ll LINF = (ll)(1e18);
const vector<int> di = { 1, 0 }, dj = { 0, 1 };
vector<vector<vector<vector<ll>>>> dp;

int main() {
	int h, w;
	cin >> h >> w;
	vector<int> r(h), c(w);
	rep(i, h) cin >> r[i];
	rep(i, w) cin >> c[i];
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	vector<vector<int>> b(h, vector<int>(w));
	rep(i, h) rep(j, w) b[i][j] = a[i][j] - '0';
	auto calc = [&]() -> ll {
		dp.assign(h, vector<vector<vector<ll>>>(w, vector<vector<ll>>(2, vector<ll>(2, LINF))));
		rep(ri, 2) {
			int ci = ri ^ b[0][0];
			dp[0][0][1][ri] = r[0] * ri + c[0] * ci;
			dp[0][0][0][ci] = r[0] * ri + c[0] * ci;
		}
		rep(i, h) rep(j, w) {
			rep(i2, 2) {
				int ni = i + di[i2], nj = j + dj[i2];
				if (ni>=h || nj>=w) continue;
				rep(j2, 2) {
					int flip = (b[ni][nj] ^ j2), cost = flip * (i2 == 0 ? r[ni] : c[nj]);
					rep(i3, 2) {
						int j3 = (i2 == i3) ? j2 : flip;
						dp[ni][nj][i3][j3] = min(dp[ni][nj][i3][j3], dp[i][j][i2][j2]+cost);
					}
				}
			}
		}
		ll rval = LINF;
		rep(i, 2) rep(j, 2) rval = min(rval, dp[h-1][w-1][i][j]);
		return rval;
	};
	ll res = calc();
	rep(i, h) rep(j, w) b[i][j] = 1 - b[i][j];
	res = min(res, calc());
	cout << res << endl;
	return 0;
}
