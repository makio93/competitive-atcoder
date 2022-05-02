// 復習0,ヒントあり,自力AC

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

const ll mod = 998244353LL;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> pq(n);
	rep(i, n) {
		cin >> pq[i].first;
		pq[i].first--;
	}
	rep(i, n) {
		cin >> pq[i].second;
		pq[i].second--;
	}
	sort(all(pq));
	vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n-k+1, vector<ll>(n+1)));
	dp[0][0][n] = 1;
	rep(i, n) rep(j, n-k+1) rep(j2, n+1) {
		if (j+1 <= n-k) dp[i+1][j+1][min(j2,pq[i].second)] = (dp[i+1][j+1][min(j2,pq[i].second)] + dp[i][j][j2]) % mod;
		if (j2 > pq[i].second) dp[i+1][j][j2] = (dp[i+1][j][j2] + dp[i][j][j2]) % mod;
	}
	ll res = 0;
	rep(i, n+1) res = (res + dp[n][n-k][i]) % mod;
	cout << res << endl;
	return 0;
}
