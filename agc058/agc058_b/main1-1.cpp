// 解説AC1-1

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
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	vector<ll> dp(n+1);
	dp[0] = 1;
	rep(i, n) {
		int li = i, ri = i;
		while (li-1>=0 && p[li-1]<=p[i]) --li;
		while (ri<n && p[ri]<=p[i]) ++ri;
		rep(j, n) if (j>=li && j<ri) dp[j+1] = (dp[j+1] + dp[j]) % mod;
	}
	cout << dp[n] << endl;
	return 0;
}
