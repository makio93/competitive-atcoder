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

// 解説を読んで自力ソースを少し書き換え

int main() {
	int n;
	cin >> n;
	vector<int> d(n), c(n), s(n);
	rep(i, n) cin >> d[i] >> c[i] >> s[i];
	int dmx = 0;
	rep(i, n) dmx = max(dmx, d[i]);
	vector<pair<int, int>> dlst(n);
	rep(i, n) dlst[i] = { d[i], i };
	sort(all(dlst));
	vector<vector<ll>> dp(2, vector<ll>(dmx+1));
	rep(i, n) rep(j, dmx+1) {
		dp[(i+1)%2][j] = dp[i%2][j];
		int id = dlst[i].second;
		if (j-c[id]>=0 && j<=d[id]) dp[(i+1)%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-c[id]]+s[id]);
	}
	ll res = 0;
	rep(i, dmx+1) res = max(res, dp[n%2][i]);
	cout << res << endl;
	return 0;
}
