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
	vector<int> x(n), y(n), p(n);
	rep(i, n) cin >> x[i] >> y[i] >> p[i];
	vector<vector<ll>> dist(n, vector<ll>(n, LINF));
	rep(i, n) rep(j, n) dist[i][j] = ((ll)abs(x[i]-x[j]) + abs(y[i]-y[j]) + (p[i]-1)) / p[i];
	rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
	ll res = LINF;
	rep(i, n) {
		ll val = 0;
		rep(j, n) val = max(val, dist[i][j]);
		res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
