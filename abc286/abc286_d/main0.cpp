// 本番AC

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
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<bool> dp(x+1), ndp;
	dp[0] = true;
	rep(i1, n) rep(i2, b[i1]) {
		ndp = dp;
		rep3(j, a[i1], x+1) if (dp[j-a[i1]]) ndp[j] = true;
		swap(dp, ndp); 
	}
	if (dp[x]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
