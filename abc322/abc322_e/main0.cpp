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
int ipow(int a, int b) {
	int val = 1;
	rep(i, b) val *= a;
	return val;
}

int main() {
	int n, k, p;
	cin >> n >> k >> p;
	vector<int> c(n);
	vector<vector<int>> a(n, vector<int>(k));
	rep(i, n) {
		cin >> c[i];
		rep(j, k) cin >> a[i][j];
	}
	int mx = ipow(p+1, k);
	vector<ll> dp(mx, LINF);
	dp[0] = 0;
	rep(i, n) {
		vector<ll> ndp = dp;
		rep(j, mx) {
			vector<int> tmp(k);
			int tval = j;
			rep(j2, k) {
				tmp[j2] = tval % (p+1);
				tval /= p+1;
			}
			rep(j2, k) tmp[j2] = min(p, tmp[j2]+a[i][j2]);
			int nval = 0;
			repr(j2, k) {
				nval *= p+1;
				nval += tmp[j2];
			}
			ndp[nval] = min(ndp[nval], dp[j]+c[i]);
		}
		swap(ndp, dp);
	}
	if (dp[mx-1] == LINF) cout << -1 << endl;
	else cout << dp[mx-1] << endl;
	return 0;
}
