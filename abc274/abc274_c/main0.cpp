// 自力AC

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

int main() {
	int n;
	cin >> n;
	vector<int> a(n), dp(n*2+1);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}
	rep(i, n) dp[i*2+1] = dp[i*2+2] = dp[a[i]] + 1;
	rep(i, 2*n+1) cout << dp[i] << endl;
	return 0;
}
