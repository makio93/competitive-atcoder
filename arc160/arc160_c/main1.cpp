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

const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	int mval = *max_element(all(a)), mb = mval + (int)ceil(log(n+1)/log(2.0));
	vector<int> b(mb+1);
	rep(i, n) b[a[i]]++;
	vector<vector<ll>> dp(mb+1);
	dp[0].assign(b[0]+2, 0);
	dp[0][b[0]] = 1;
	rep(i, mb) {
		int plen = dp[i].size(), tlen = max(1, (plen+2)/2+b[i+1]+1);
		dp[i+1].assign(tlen+1, 0);
		rep(j, plen) {
			dp[i+1][b[i+1]] = (dp[i+1][b[i+1]] + dp[i][j]) % mod;
			dp[i+1][b[i+1]+j/2+1] = (dp[i+1][b[i+1]+j/2+1] - dp[i][j] + mod) % mod;
		}
		rep(j, tlen) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i+1][j]) % mod;
	}
	ll res = 0;
	for (const ll& vi : dp[mb]) res = (res + vi) % mod;
	cout << res << endl;
	return 0;
}
