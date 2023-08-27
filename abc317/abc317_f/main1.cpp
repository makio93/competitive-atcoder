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

const int INF = (int)(1e9);
const ll mod = 998244353LL;

int main() {
	ll n;
	int a1, a2, a3;
	cin >> n >> a1 >> a2 >> a3;
	vector dp(61, vector(1<<3, vector(a1, vector(a2, vector(a3, 0LL)))));
	dp[0][0][0][0][0] = 1;
	rep(i1, 60) rep(i2, 1<<3) rep(j1, a1) rep(j2, a2) rep(j3, a3) rep(k, 1<<3) {
		int k1 = k & 1, k2 = (k>>1) & 1, k3 = (k>>2) & 1;
		if ((k1^k2^k3) != 0) continue;
		int ti = i2;
		if (!((n>>i1)&1)) {
			if (!(ti&1) && k1) ti ^= 1;
			if (!((ti>>1)&1) && k2) ti ^= 1<<1;
			if (!((ti>>2)&1) && k3) ti ^= 1<<2;
		}
		else {
			if ((ti&1) && !k1) ti ^= 1;
			if (((ti>>1)&1) && !k2) ti ^= 1<<1;
			if (((ti>>2)&1) && !k3) ti ^= 1<<2;
		}
		dp[i1+1][ti][(j1+((ll)(k1)<<i1))%a1][(j2+((ll)(k2)<<i1))%a2][(j3+((ll)(k3)<<i1))%a3] = (dp[i1+1][ti][(j1+((ll)(k1)<<i1))%a1][(j2+((ll)(k2)<<i1))%a2][(j3+((ll)(k3)<<i1))%a3] + dp[i1][i2][j1][j2][j3]) % mod;
	}
	ll res = dp[60][0][0][0][0];
	res = (res - n / lcm(a2, a3) % mod + mod) % mod;
	res = (res - n / lcm(a1, a3) % mod + mod) % mod;
	res = (res - n / lcm(a1, a2) % mod + mod) % mod;
	res = (res - 1 + mod) % mod;
	cout << res << endl;
	return 0;
}
