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
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<tuple<ll, int, int>> edges;
	rep(i, n) edges.emplace_back((ll)(y[i]+100)*(y[i]+100), i, n);
	rep(i, n) edges.emplace_back((ll)(100-y[i])*(100-y[i]), i, n+1);
	rep(i, n) rep3(j, i+1, n) edges.emplace_back((ll)(x[i]-x[j])*(x[i]-x[j])+(ll)(y[i]-y[j])*(y[i]-y[j]), i, j);
	sort(all(edges));
	dsu d(n+2);
	ll rval = 0;
	int m = edges.size();
	rep(i, m) {
		d.merge(get<1>(edges[i]), get<2>(edges[i]));
		if (d.same(n, n+1)) {
			rval = get<0>(edges[i]);
			break;
		}
	}
	cout << fixed << setprecision(5) << (sqrt(rval)/2.0) << endl;
	return 0;
}
