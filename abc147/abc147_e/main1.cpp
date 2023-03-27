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

const int INF = (int)(1e9);

int main() {
	int h, w;
	cin >> h >> w;
	vector a(h, vector(w, 0)), b(h, vector(w, 0));
	rep(i, h) rep(j, w) cin >> a[i][j];
	rep(i, h) rep(j, w) cin >> b[i][j];
	int kl = 0;
	rep(i, h) rep(j, w) kl = max(kl, abs(a[i][j]-b[i][j]));
	kl *= h + w;
	vector dp(h, vector(w, vector(kl+1, false)));
	dp[0][0][abs(a[0][0]-b[0][0])] = true;
	rep(i, h) rep(j, w) {
		if (i==0 && j==0) continue;
		int val = abs(a[i][j]-b[i][j]);
		rep(k, kl+1) {
			if (i-1 >= 0) {
				if (abs(k-val) <= kl) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][abs(k-val)];
				if (k+val <= kl) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k+val];
			}
			if (j-1 >= 0) {
				if (abs(k-val) <= kl) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][abs(k-val)];
				if (k+val <= kl) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k+val];
			}
		}
	}
	int res = INF;
	rep(i, kl+1) if (dp[h-1][w-1][i]) res = min(res, i);
	cout << res << endl;
	return 0;
}
