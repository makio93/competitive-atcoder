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

// 自力で実装、AC

using mint = modint1000000007;
const string tar = "atcoder";

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<char, int>> run;
	run.emplace_back(s.front(), 1);
	rep3(i, 1, n) {
		if (s[i] == run.back().first) run.back().second++;
		else run.emplace_back(s[i], 1);
	}
	int m = run.size();
	vector<vector<mint>> dp(m+1, vector<mint>(7));
	rep(i, m) rep(j, 7) {
		if (run[i].first == tar[j]) {
			if (j-1 >= 0) dp[i+1][j] += dp[i][j-1] * run[i].second;
			else dp[i+1][j] += run[i].second;
		}
		dp[i+1][j] += dp[i][j];
	}
	cout << dp[m][6].val() << endl;
	return 0;
}
