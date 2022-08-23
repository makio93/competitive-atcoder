// 自力AC

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

const double DINF = (double)(1e18);

int main() {
	int xs, ys, xt, yt, n;
	cin >> xs >> ys >> xt >> yt >> n;
	vector<int> x(n), y(n), r(n);
	rep(i, n) cin >> x[i] >> y[i] >> r[i];
	vector<vector<double>> g(n+2, vector<double>(n+2));
	g[n][n+1] = g[n+1][n] = sqrt((ll)(xs-xt)*(xs-xt) + (ll)(ys-yt)*(ys-yt));
	rep(i, n) g[n][i] = g[i][n] = max(0.0, sqrt((ll)(xs-x[i])*(xs-x[i])+(ll)(ys-y[i])*(ys-y[i]))-r[i]);
	rep(i, n) g[n+1][i] = g[i][n+1] = max(0.0, sqrt((ll)(xt-x[i])*(xt-x[i])+(ll)(yt-y[i])*(yt-y[i]))-r[i]);
	rep(i, n) rep(j, n) g[i][j] = g[j][i] = max(0.0, sqrt((ll)(x[j]-x[i])*(x[j]-x[i])+(ll)(y[j]-y[i])*(y[j]-y[i]))-((ll)r[i]+r[j]));
	vector<double> dist(n+2, DINF);
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	dist[n] = 0.0;
	pq.emplace(0.0, n);
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		double di = pi.first;
		int vi = pi.second;
		if (dist[vi] != di) continue;
		rep(i, n+2) {
			double ndi = di + g[vi][i];
			if (dist[i] <= ndi) continue;
			dist[i] = ndi;
			pq.emplace(ndi, i);
		}
	}
	printf("%.14f\n", dist[n+1]);
	return 0;
}
