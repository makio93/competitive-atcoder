// 終了後,自力AC

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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> p(n), q(n);
	dsu d(2*n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
		d.merge(p[i], n+p[i]);
	}
	rep(i, n) {
		cin >> q[i];
		q[i]--;
		d.merge(n+q[i], q[i]);
		d.merge(p[i], n+q[i]);
	}
	vector<vector<mint>> dp(n+1, vector<mint>(2));
	dp[0][0] = 1;
	rep(i, n) {
		dp[i+1][1] += dp[i][0];
		dp[i+1][0] += dp[i][0] + dp[i][1];
	}
	auto glst = d.groups();
	mint res = 1;
	rep(i, (int)(glst.size())) {
		int m = glst[i].size() / 2;
		mint val = 0;
		if (m == 1) val += 1;
		else if (m == 2) val += 3;
		else val += (dp[m-2][0]+dp[m-2][1]) + (dp[m-3][0]+dp[m-3][1]) * 2;
		res *= val;
	}
	cout << res.val() << endl;
	return 0;
}
