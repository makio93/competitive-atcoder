// 自力AC

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
	int n, p;
	cin >> n >> p;
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	vector<vector<ll>> dp(n+1, vector<ll>(n));
	rep3(i, 1, n+1) {
		int ten = 1, tcnt = 0;
		while (ten <= i) {
			ten *= 10;
			++tcnt;
		}
		dp[i][tcnt] += 26;
		rep(j, n) {
			int li = 1;
			rep(j2, tcnt) {
				int ri = li * 10;
				dp[i][min(n-1,j+2+j2)] = (dp[i][min(n-1,j+2+j2)] + (dp[max(0,i-li)][j] - dp[max(0,i-ri)][j] + p) * 25) % p;
				li *= 10;
			}
		}
		rep(j, n) dp[i][j] = (dp[i][j] + dp[i-1][j]) % p;
	}
	ll res = 0;
	rep(i, n-1) res = (res + dp[n][i] - dp[n-1][i] + p) % p;
	cout << res << endl;
	return 0;
}
