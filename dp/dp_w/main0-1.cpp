// 自力WA1

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
	int n, m;
	cin >> n >> m;
	vector<int> l(m), r(m), a(m);
	rep(i, m) cin >> l[i] >> r[i] >> a[i];
	vector<int> ord(m);
	iota(all(ord), 0);
	sort(all(ord), [&](int li, int ri) -> bool { return make_pair(l[li], r[li]) < make_pair(l[ri], r[ri]); });
	vector<ll> dp(n+1, -LINF);
	dp[0] = 0;
	int mi = 0;
	rep(i, n) {
		ll nv = dp[i];
		while (mi<m && l[mi]==i+1) {
			nv += a[mi];
			dp[r[mi]] = max(dp[r[mi]], dp[i]);
			++mi;
		}
		dp[i+1] = max(dp[i+1], nv);
	}
	cout << dp[n] << endl;
	return 0;
}
