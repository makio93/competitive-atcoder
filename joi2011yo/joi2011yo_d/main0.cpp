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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<ll>> dp(n-1, vector<ll>(21));
	dp[0][a[0]] = 1;
	rep(i, n-2) rep(j, 21) {
		for (int sub : { a[i+1], -a[i+1] }) if (j+sub>=0 && j+sub<=20) dp[i+1][j+sub] += dp[i][j];
	}
	cout << dp[n-2][a[n-1]] << endl;
	return 0;
}
