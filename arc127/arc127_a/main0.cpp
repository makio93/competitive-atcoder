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

// 本番WA

int main() {
	string n;
	cin >> n;
	int nlen = n.length();
	vector<vector<vector<vector<ll>>>> dp(nlen+1, vector<vector<vector<ll>>>(10, vector<vector<ll>>(3, vector<ll>(nlen+1))));
	vector<vector<vector<vector<ll>>>> dp2(nlen+1, vector<vector<vector<ll>>>(10, vector<vector<ll>>(3, vector<ll>(nlen+1))));
	dp[0][0][0][0] = 1;
	dp2[0][0][0][0] = 1;
	rep3(i, 1, nlen+1) rep(j, 10) {
		if (j != 1) {
			rep(j2, nlen+1) rep(j3, 10) {
				dp[i][j][0][j2] += dp[i-1][j3][0][j2];
				dp[i][j][2][j2] += dp[i-1][j3][2][j2] + dp[i-1][j3][1][j2];
				if (j < (int)(n[nlen-i]-'0')) {
					dp2[i][j][0][j2] += dp[i-1][j3][0][j2];
					dp2[i][j][2][j2] += dp[i-1][j3][2][j2] + dp[i-1][j3][1][j2];
				}
				else if (j == (int)(n[nlen-i]-'0')) {
					if (nlen-i+1>=nlen || j3<(int)(n[nlen-i+1]-'0')) {
						dp2[i][j][0][j2] += dp[i-1][j3][0][j2];
						dp2[i][j][2][j2] += dp[i-1][j3][2][j2] + dp[i-1][j3][1][j2];
					}
					else if (j3==(int)(n[nlen-i+1]-'0')) {
						dp2[i][j][0][j2] += dp2[i-1][j3][0][j2];
						dp2[i][j][2][j2] += dp2[i-1][j3][2][j2] + dp2[i-1][j3][1][j2];
					}
				}
			}
		}
		else {
			rep(j2, nlen+1) rep(j3, 10) {
				if (j2-1>=0) dp[i][j][1][j2] += dp[i-1][j3][0][j2-1] + dp[i-1][j3][1][j2-1];
				dp[i][j][2][j2] += dp[i-1][j3][2][j2];
				if (j < (int)(n[nlen-i]-'0')) {
					if (j2-1>=0) dp2[i][j][1][j2] += dp[i-1][j3][0][j2-1] + dp[i-1][j3][1][j2-1];
					dp2[i][j][2][j2] += dp[i-1][j3][2][j2];
				}
				else if (j == (int)(n[nlen-i]-'0')) {
					if (nlen-i+1>=nlen || j3<(int)(n[nlen-i+1]-'0')) {
						if (j2-1>=0) dp2[i][j][1][j2] += dp[i-1][j3][0][j2-1] + dp[i-1][j3][1][j2-1];
						dp2[i][j][2][j2] += dp[i-1][j3][2][j2];
					}
					else if (j3==(int)(n[nlen-i+1]-'0')) {
						if (j2-1>=0) dp2[i][j][1][j2] += dp2[i-1][j3][0][j2-1] + dp2[i-1][j3][1][j2-1];
						dp2[i][j][2][j2] += dp2[i-1][j3][2][j2];
					}
				}
			}
		}
	}
	ll res = 0;
	rep(i, 10) rep(j, 3) rep3(j2, 1, nlen+1) {
		res += dp2[nlen][i][j][j2] * j2;
	}
	cout << res << endl;
	return 0;
}
