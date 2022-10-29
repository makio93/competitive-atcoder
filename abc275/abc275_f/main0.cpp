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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> dp(2, vector<int>(m+1, INF)), ndp;
	dp[1][0] = 0;
	rep(i, n) {
		ndp.assign(2, vector<int>(m+1, INF));
		rep(j, m+1) {
			if (j-a[i] >= 0) {
				if (dp[0][j-a[i]] != INF) chmin(ndp[1][j], dp[0][j-a[i]]);
				if (dp[1][j-a[i]] != INF) chmin(ndp[1][j], dp[1][j-a[i]]);
			}
			if (dp[0][j] != INF) chmin(ndp[0][j], dp[0][j]);
			if (dp[1][j] != INF) chmin(ndp[0][j], dp[1][j]+1);
		}
		swap(dp, ndp);
	}
	rep3(i, 1, m+1) {
		if (min(dp[0][i], dp[1][i]) != INF) cout << min(dp[0][i], dp[1][i]) << endl;
		else cout << -1 << endl;
	}
	return 0;
}
