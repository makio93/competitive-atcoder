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

const ll mod = (ll)(1e9) + 7;

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<ll> dp(n+2);
	dp[0] = 1;
	rep(i, n) rep3r(j, -1, i) {
		dp[i+2] = (dp[i+2] + dp[j+1]) % mod;
		if (j>=0 && s[i]==s[j]) break;
	}
	ll res = 0;
	rep3(i, 2, n+2) res = (res + dp[i]) % mod;
	cout << res << endl;
	return 0;
}
