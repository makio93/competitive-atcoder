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
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dp(n+1, vector<ll>(10));
	pair<int, int> mval = { -1, -1 };
	rep(i, n) rep3(j, 1, 10) {
		dp[i+1][j] = (dp[i][j] * 10 + j) % m;
		if (dp[i+1][j] == 0) mval = max(mval, { i+1, j });
	}
	if (mval.first == -1) cout << -1 << endl;
	else cout << string(mval.first, (char)(mval.second+'0')) << endl;
	return 0;
}
