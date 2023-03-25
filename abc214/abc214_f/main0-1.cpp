// バチャ本番,自力WA1

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
const ll mod = (ll)(1e9) + 7;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> runs;
	runs.push_back(1);
	rep3(i, 1, n) {
		if (s[i] == s[i-1]) runs.back()++;
		else runs.push_back(1);
	}
	int m = runs.size();
	vector dp(m+1, vector(4, 0LL));
	dp[0][0] = 1;
	rep(i, m) {
		if (runs[i] == 1) {
			rep(j, 4) {
				dp[i+1][0] += dp[i][j];
				dp[i+1][0] %= mod;
				if ((j&2) == 0) {
					dp[i+1][3] += dp[i][j];
					dp[i+1][3] %= mod;
				}
			}
		}
		else if (runs[i]%2 == 0) {
			rep(j, 4) {
				dp[i+1][0] += dp[i][j] * (runs[i]/2);
				dp[i+1][0] %= mod;
			}
			rep(j, 4) {
				if (j&2) {
					dp[i+1][2] += dp[i][j];
					dp[i+1][2] %= mod;
				}
				else {
					dp[i+1][1] += dp[i][j];
					dp[i+1][1] %= mod;
				}
			}
		}
		else {
			rep(j, 4) {
				dp[i+1][0] += dp[i][j] * (runs[i]/2+1);
				dp[i+1][0] %= mod;
			}
			rep(j, 4) {
				if (!(j&2)) {
					dp[i+1][3] += dp[i][j];
					dp[i+1][3] %= mod;
				}
			}
		}
	}
	ll res = 0;
	rep(i, 4) {
		res += dp[m][i];
		res %= mod;
	}
	cout << res << endl;
	return 0;
}
