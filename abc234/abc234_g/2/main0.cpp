// 学習2回目,バチャ本番,自力WA

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

const int INF = (int)(2e9);
const ll mod = 998244353LL;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> dp(n+1);
	stack<pair<int, ll>> rst, lst;
	rst.emplace(INF, 1);
	lst.emplace(0, 1);
	dp[0] = 1;
	rep(i, n) {
		ll rval = 0, lval = 0;
		while (rst.top().first <= a[i]) {
			rval = (rval + rst.top().second) % mod;
			rst.pop();
		}
		rval = (rval + rst.top().second) % mod;
		while (lst.top().first >= a[i]) {
			lval = (lval + lst.top().second) % mod;
			lst.pop();
		}
		lval = (lval + lst.top().second) % mod;
		dp[i+1] = ((rval - lval + mod) % mod * a[i]) % mod;
		rst.emplace(a[i], (rval+dp[i+1])%mod);
		lst.emplace(a[i], (lval+dp[i+1])%mod);
	}
	cout << dp[n] << endl;
	return 0;
}
