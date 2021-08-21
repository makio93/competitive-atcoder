#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<ll> dp(n+1);
	dp[0] = 1;
	rep(i, n) {
		dp[i+1] = (dp[i+1] + dp[0]) % mod;
		rep(j, i) if (s[i] == s[j]) dp[i+1] = (dp[i+1] + dp[j+1]) % mod;
	}
	ll res = 0;
	rep3(i, 1, n+1) res = (res + dp[i]) % mod;
	cout << res << endl;
	return 0;
}
