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

// 本番後,自力TLE

const ll INF = (ll)(1e18);

int main() {
	int h, w, h1, w1, h2, w2;
	cin >> h >> w >> h1 >> w1 >> h2 >> w2;
	h2 = min(h2, h1);
	w2 = min(w2, w1);
	vector<vector<ll>> a(h, vector<ll>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<vector<ll>> sum(h+1, vector<ll>(w+1));
	rep(i, h) rep(j, w) sum[i+1][j+1] += a[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
	ll res = 0;
	rep(i, h-h1+1) rep(j, w-w1+1) {
		ll val1 = sum[i+h1][j+w1] - sum[i+h1][j] - sum[i][j+w1] + sum[i][j];
		ll mval = INF;
		rep(i2, h1-h2+1) rep(j2, w1-w2+1) {
			ll val2 = sum[i+i2+h2][j+j2+w2] - sum[i+i2+h2][j+j2] - sum[i+i2][j+j2+w2] + sum[i+i2][j+j2];
			mval = min(mval, val1-val2);
		}
		res = max(res, mval);
	}
	cout << res << endl;
	return 0;
}
