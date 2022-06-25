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
	int n;
	cin >> n;
	vector<int> c(9);
	rep(i, 9) cin >> c[i];
	vector<vector<int>> dp(n+1, vector<int>(10));
	repr(i, 9) for (int j=0; j+c[i]<=n; ++j) {
		auto ndp = dp[j];
		ndp[0]++;
		ndp[9-i]++;
		dp[j+c[i]] = max(dp[j+c[i]], ndp);
	}
	vector<int> rdp(10);
	rep(i, n+1) rdp = max(rdp, dp[i]);
	string res;
	rep3(i, 1, 10) res += string(rdp[i], (char)('0'+10-i));
	cout << res << endl;
	return 0;
}
