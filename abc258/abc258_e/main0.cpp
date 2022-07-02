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
	int n, q, x;
	cin >> n >> q >> x;
	vector<int> w(n);
	rep(i, n) cin >> w[i];
	ll asum = 0;
	rep(i, n) asum += w[i];
	vector<ll> wsums(n*2+1);
	rep(i, 2*n) wsums[i+1] = wsums[i] + w[i%n];
	vector<vector<ll>> dp(40, vector<ll>(n));
	vector<ll> acnt(n);
	rep(i, n) {
		acnt[i] = x / asum * n;
		ll tar = x % asum;
		int tid = lower_bound(all(wsums), wsums[i]+tar) - wsums.begin();
		acnt[i] += tid - i;
		dp[0][i] = tid % n;
	}
	rep(i, 39) rep(j, n) dp[i+1][j] = dp[i][dp[i][j]];
	rep(i, q) {
		ll ki;
		cin >> ki;
		ll ktar = ki - 1;
		int tid = 0;
		repr(j, 40) if ((ktar>>j)&1) tid = dp[j][tid];
		cout << acnt[tid] << endl;
	}
	return 0;
}
