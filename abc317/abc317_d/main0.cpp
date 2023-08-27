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

const ll LINF = (ll)(1e18);

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n), z(n);
	rep(i, n) cin >> x[i] >> y[i] >> z[i];
	int lz = 0, az = accumulate(all(z), 0), tz = (az + 1) / 2;
	vector<int> cl, vl;
	rep(i, n) {
		if (x[i] > y[i]) lz += z[i];
		else {
			cl.push_back((y[i]-x[i]+1)/2);
			vl.push_back(z[i]);
		}
	}
	if (lz >= tz) {
		cout << 0 << endl;
		return 0;
	}
	int m = cl.size();
	vector<ll> dp(tz+1, LINF);
	dp[lz] = 0;
	rep(i, m) {
		vector<ll> ndp = dp;
		rep(j, tz+1) if (dp[j] != LINF) ndp[min(tz, j+vl[i])] = min(ndp[min(tz, j+vl[i])], dp[j]+cl[i]);
		swap(ndp, dp);
	}
	cout << dp[tz] << endl;
	return 0;
}
