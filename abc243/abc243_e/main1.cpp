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

const ll INF = (ll)(1e17);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<ll> c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	vector<vector<ll>> dist(n, vector<ll>(n, INF));
	rep(i, m) dist[a[i]][b[i]] = dist[b[i]][a[i]] = c[i];
	rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min({ INF, dist[i][j], dist[i][k]+dist[k][j], dist[j][k]+dist[k][i] });
	int res = 0;
	rep(i, m) {
		rep(j, n) if (dist[a[i]][j]+dist[j][b[i]] <= c[i]) {
			++res;
			break;
		}
	}
	cout << res << endl;
	return 0;
}
