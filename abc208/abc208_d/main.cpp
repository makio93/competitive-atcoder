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

const ll INF = (ll)(1e15);

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	ll ans = 0;
	rep(i, n) dist[i][i] = 0;
	rep(i, m) {
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		--ai; --bi;
		dist[ai][bi] = ci;
	}
	rep(k, n) {
		rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
		rep(i, n) rep(j, n) if (dist[i][j] != INF) ans += dist[i][j];
	}
	cout << ans << endl;
	return 0;
}
