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

// ヒントだけみて実装、AC

const ll INF = (ll)(1e15);

int main() {
	int n;
	cin >> n;
	vector<int> a(2*n);
	rep(i, 2*n) cin >> a[i];
	vector<vector<ll>> dp(2*n+1, vector<ll>(2*n+1, INF));
	rep(i, 2*n+1) dp[i][i] = 0;
	for (int h=2; h<=2*n; h+=2) {
		for (int l=0; l+h<=2*n; ++l) {
			int r = l + h;
			dp[l][r] = min(dp[l][r], dp[l+1][r-1]+llabs(a[l]-a[r-1]));
			for (int k=l+2; k<r; k+=2) dp[l][r] = min(dp[l][r], dp[l][k]+dp[k][r]);
		}
	}
	cout << dp[0][2*n] << endl;
	return 0;
}
