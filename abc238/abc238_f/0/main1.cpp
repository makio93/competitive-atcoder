// 復習0,解説AC

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

const ll mod = 998244353LL;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n), q(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) {
		cin >> q[i];
		q[i]--;
	}
	vector<int> v(n);
	rep(i, n) v[p[i]] = q[i];
	vector<vector<ll>> dp(k+1, vector<ll>(n+1));
	dp[0][n] = 1;
	rep(i, n) {
		vector<vector<ll>> ndp(k+1, vector<ll>(n+1));
		rep(j, k+1) rep(j2, n+1) {
			if (j+1<=k && j2>v[i]) ndp[j+1][j2] = (ndp[j+1][j2] + dp[j][j2]) % mod;
			ndp[j][min(j2, v[i])] = (ndp[j][min(j2, v[i])] + dp[j][j2]) % mod;
		}
		swap(dp, ndp);
	}
	ll res = 0;
	rep(i, n+1) res = (res + dp[k][i]) % mod;
	cout << res << endl;
	return 0;
}
