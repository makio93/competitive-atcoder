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

const ll mod = 998244353LL;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>((1<<10), vector<ll>(10)));
	rep(i, n) {
		if (i-1 >= 0) {
			dp[i] = dp[i-1];
			int sid = s[i] - 'A';
			rep(i2, (1<<10)) {
				if (!((i2>>sid)&1)) {
					rep(j2, 10) dp[i][i2|(1<<sid)][sid] = (dp[i][i2|(1<<sid)][sid] + dp[i-1][i2][j2]) % mod;
				}
				else {
					rep(j2, 10) if (j2 == sid) dp[i][i2][sid] = (dp[i][i2][sid] + dp[i-1][i2][sid]) % mod;
				}
			}
		}
		dp[i][(1<<(s[i]-'A'))][s[i]-'A'] = (dp[i][(1<<(s[i]-'A'))][s[i]-'A'] + 1) % mod;
	}
	ll res = 0;
	rep(i, (1<<10)) rep(j, 10) res = (res + dp[n-1][i][j]) % mod;
	cout << res << endl;
	return 0;
}
