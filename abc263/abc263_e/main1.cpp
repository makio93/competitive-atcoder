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

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n-1) cin >> a[i];
	vector<mint> dp(n+1);
	repr(i, n-1) {
		int li = i+1, ri = i+a[i]+1;
		dp[i] = mint(1) / a[i] + (dp[li] - dp[ri]) / a[i] + 1;
		dp[i] += dp[i+1];
	}
	cout << (dp[0]-dp[1]).val() << endl;
	return 0;
}
