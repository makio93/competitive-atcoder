#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番後,自力AC1,余事象的な遷移

const ll mod = 998244353LL;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> rg(n);
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		rg[ui].push_back(vi);
		rg[vi].push_back(ui);
	}
	rep(i, n) rg[i].push_back(i);
	vector<vector<ll>> dp(k+1);
	dp[0] = vector<ll>(n);
	ll sum = dp[0][0] = 1;
	rep(i, k) {
		dp[i+1] = vector<ll>(n, sum);
		sum = sum * n % mod;
		rep(j, n) {
			for (int t : rg[j]) {
				dp[i+1][t] = (dp[i+1][t] - dp[i][j] + mod) % mod;
				sum = (sum - dp[i][j] + mod) % mod;
			}
		}
	}
	cout << dp[k][0] << endl;
	return 0;
}
