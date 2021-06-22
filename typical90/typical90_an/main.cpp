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

// ほぼ自力解答、WA

const ll BIG = (ll)(1e15);
const ll ADD = (ll)(1e9);

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) b[i] = w - a[i];
	mcf_graph<int, ll> g(n+2);
	rep(i, n) {
		g.add_edge(n, i, 1, ADD);
		g.add_edge(i, n+1, 1, ADD+b[i]);
	}
	rep(i, n) {
		int ki;
		cin >> ki;
		rep(j, ki) {
			int cj;
			cin >> cj;
			--cj;
			g.add_edge(i, cj, 1, BIG);
		}
	}
	pair<int, ll> mval = g.flow(n, n+1);
	ll res = max(0LL, ll(-(mval.second - mval.first*2*ADD)+1));
	cout << res << endl;
	return 0;
}
