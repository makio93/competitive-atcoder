// 本番,未完成,解答不能

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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n-1) cin >> a[i];
	vector<mint> dp(n), sub(n+1);
	rep(i, n) {
		if (i-1 >= 0) sub[i] += sub[i-1];
		dp[i] += sub[i];
		if (i == n-1) break;
		int li = i + 1, ri = i + a[i] + 1;
		mint nval = (dp[i] + (mint)(a[i]+1)/a[i])/a[i];
		sub[li] += nval;
		sub[ri] -= nval;
	}
	cout << dp[n-1].val() << endl;
	return 0;
}
