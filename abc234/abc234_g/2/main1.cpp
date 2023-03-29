// 学習2回目,解説AC

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
	dp[0] = 1;
	rst.emplace(INF, 0);
	lst.emplace(0, 0);
	ll rsum = 0, lsum = 0;
	rep(i, n) {
		ll rval = dp[i], lval = dp[i];
		while (rst.top().first <= a[i]) {
			rval = (rval + rst.top().second) % mod;
			rsum = (rsum - rst.top().first * rst.top().second % mod + mod) % mod;
			rst.pop();
		}
		rst.emplace(a[i], rval);
		rsum = (rsum + rval * a[i] % mod) % mod;
		while (lst.top().first >= a[i]) {
			lval = (lval + lst.top().second) % mod;
			lsum = (lsum - lst.top().first * lst.top().second % mod + mod) % mod;
			lst.pop();
		}
		lst.emplace(a[i], lval);
		lsum = (lsum + lval * a[i] % mod) % mod;
		dp[i+1] = (rsum - lsum + mod) % mod;
	}
	cout << dp[n] << endl;
	return 0;
}
