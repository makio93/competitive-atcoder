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

// 解説AC

using mint = modint998244353;

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	int x1, y1, x2, y2;
	cin >> y1 >> x1 >> y2 >> x2;
	--x1; --y1; --x2; --y2;
	const vector<int> my = { 1, h-1 }, mx = { 1, w-1 };
	vector<vector<mint>> dp(2, vector<mint>(2));
	dp[0][0] = 1;
	rep(i1, k) {
		vector<vector<mint>> ndp(2, vector<mint>(2));
		rep(i, 2) rep(j, 2) {
			rep(i2, 2) {
				ndp[i2][j] += dp[i][j] * (my[i2] - (i2==i ? 1 : 0));
				ndp[i][i2] += dp[i][j] * (mx[i2] - (i2==j ? 1 : 0));
			}
		}
		swap(ndp, dp);
	}
	int yid = (y1==y2 ? 0 : 1), xid = (x1==x2 ? 0 : 1);
	cout << (dp[yid][xid]/my[yid]/mx[xid]).val() << endl;
	return 0;
}
