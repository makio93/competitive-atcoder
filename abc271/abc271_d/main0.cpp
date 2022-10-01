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
	int n, s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<vector<bool>> dp(n+1, vector<bool>(s+1));
	dp[0][0] = true;
	rep(i, n) rep(j, s+1) if (dp[i][j]) {
		if (j+a[i] <= s) dp[i+1][j+a[i]] = true;
		if (j+b[i] <= s) dp[i+1][j+b[i]] = true;
	}
	if (!dp[n][s]) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		string res;
		int id = s;
		repr(i, n) {
			if (id-a[i]>=0 && dp[i][id-a[i]]) {
				res.push_back('H');
				id -= a[i];
			}
			else if (id-b[i]>=0 && dp[i][id-b[i]]) {
				res.push_back('T');
				id -= b[i];
			}
		}
		reverse(all(res));
		cout << res << endl;
	}
	return 0;
}
