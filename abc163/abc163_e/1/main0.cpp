// 学習1回目,バチャ本番AC

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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool {
		return a[li] > a[ri];
	});
	vector<vector<ll>> dp(n+1, vector<ll>(n+1));
	rep(i, n) rep(j, i+1) {
		int li = j, ri = (n-1) - (i-j);
		dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+(ll)a[ord[i]]*abs(li-ord[i]));
		dp[i+1][j] = max(dp[i+1][j], dp[i][j]+(ll)a[ord[i]]*abs(ri-ord[i]));
	}
	ll res = 0;
	rep(i, n+1) res = max(res, dp[n][i]);
	cout << res << endl;
	return 0;
}
