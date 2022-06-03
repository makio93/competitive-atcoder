// 復習1回目,自力AC

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
	vector<vector<pair<int, int>>> xyz(n);
	rep(i, m) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi;
		--xi; --yi;
		xyz[xi].emplace_back(yi, zi);
	}
	vector<vector<ll>> dp(n+1, vector<ll>(1<<n));
	dp[0][0] = 1;
	rep(i, n) rep(j, (1<<n)) rep(j2, n) if (!((j>>j2)&1)) {
		int nj = j | (1<<j2);
		bool ok = true;
		rep(k, (int)(xyz[i].size())) if (__builtin_popcount(nj&((1<<(xyz[i][k].first+1))-1)) > xyz[i][k].second) ok = false;
		if (ok) dp[i+1][nj] += dp[i][j];
	}
	cout << dp[n][(1<<n)-1] << endl;
	return 0;
}
