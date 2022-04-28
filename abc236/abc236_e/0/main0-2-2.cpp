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

// ヒント付きで自力考察2,AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	double l = 0.0, r = 1.1e9;
	while (r-l > 1e-6) {
		double c = l + (r-l) / 2.0;
		vector<double> dp(n+1, -1.1e15);
		dp[0] = 0.0;
		rep(i, n) rep(j, 2) if (i-j >= 0) dp[i+1] = max(dp[i+1], dp[i-j]+a[i]-c);
		bool ok = false;
		rep(i, 2) if (dp[n-i] >= 0.0) ok = true;
		if (ok) l = c;
		else r = c;
	}
	printf("%.10f\n", l);
	int li = 0, ri = (int)(1.1e9);
	while (ri-li > 1) {
		int ci = li + (ri-li) / 2;
		vector<int> dp(n+1, (int)(-1e9));
		dp[0] = 0;
		rep(i, n) rep(j, 2) if (i-j >= 0) dp[i+1] = max(dp[i+1], dp[i-j]+(a[i]>=ci?1:-1));
		bool ok = false;
		rep(i, 2) if (dp[n-i] > 0) ok = true;
		if (ok) li = ci;
		else ri = ci;
	}
	cout << li << endl;
	return 0;
}
