// 学習1回目,自力WA

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

const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<ll>> dp0(n+1, vector<ll>(2, LINF)), dp1(n, vector<ll>(2, LINF));
	dp0[0][0] = 0;
	rep3(i, 1, n+1) {
		dp0[i][0] = min({ LINF, dp0[i-1][0]+b[i-1], dp0[i-1][1] });
		if (i != n) dp0[i][1] = min(LINF, dp0[i-1][0]+a[i]);
	}
	dp1[0][1] = a[0];
	rep3(i, 1, n) {
		dp1[i][0] = min({ LINF, dp1[i-1][0]+b[i-1], dp1[i-1][1] });
		if (i != n-1) dp1[i][1] = min(LINF, dp1[i-1][0]+a[i]);
	}
	ll res = min(dp0[n][0], dp1[n-1][0]);
	cout << res << endl;
	return 0;
}
