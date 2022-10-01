// 解説AC

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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	vector<int> e(k);
	rep(i, k) {
		cin >> e[i];
		e[i]--;
	}
    vector<ll> dp(n, LINF);
    dp[0] = 0;
    rep(i, k) if (dp[a[e[i]]] < LINF) dp[b[e[i]]] = min(dp[b[e[i]]], dp[a[e[i]]]+c[e[i]]);
    ll res = (dp[n-1] == LINF) ? -1 : dp[n-1];
    cout << res << endl;
    return 0;
}
