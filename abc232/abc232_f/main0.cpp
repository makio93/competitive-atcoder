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

// 本番実装,WA

const ll INF = (ll)(2e18);

int main() {
	int n;
	ll x, y;
	cin >> n >> x >> y;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<ll>> costs(n, vector<ll>(n, INF));
	rep(i, n) {
		costs[i][i] = abs(a[i]-b[i]) * x;
		rep(j, n) if (j != i) {
			ll cost = 0;
			if (j < i) rep3(j2, j+1, i+1) cost += min(y, abs(a[j2]-a[j])*x*2);
			else rep3r(j2, i, j) cost += min(y, abs(a[j2]-a[j])*x*2);
			cost += abs(a[j]-b[i])*x;
			costs[i][j] = cost;
		}
	}
	mcf_graph<int, ll> g(n*2+2);
	rep(i, n) rep(j, n) g.add_edge(i, n+j, 1, costs[i][j]);
	rep(i, n) g.add_edge(n*2, i, 1, 0);
	rep(i, n) g.add_edge(n+i, n*2+1, 1, 0);
	g.flow(n*2, n*2+1, n);
	vector<int> tar(n);
	rep(i, n) rep(j, n) if (g.get_edge(i*n+j).flow == 1) tar[i] = j;
	ll res = 0;
	rep(i, n) {
		res += abs(a[tar[i]]-b[i]) * x;
		if (tar[i] < i) {
			rep3(j, tar[i]+1, i+1) res += min(y, abs(a[j]-a[tar[i]])*x*2);
			rep3(j, tar[i]+1, i+1) swap(a[j-1], a[j]);
		}
		else if (tar[i] > i) {
			rep3r(j, i, tar[i]) res += min(y, abs(a[j]-a[tar[i]])*x*2);
			rep3r(j, i, tar[i]) swap(a[j], a[j+1]);
		}
	}
	cout << res << endl;
	return 0;
}
