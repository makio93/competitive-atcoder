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

// 解説を一部読み、最小カットを実装、AC

const ll BIG = (ll)(1e15);

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	ll sum = 0;
	rep(i, n) sum += a[i];
	mf_graph<ll> g(n+2);
	rep(i, n) {
		g.add_edge(n, i, (ll)(a[i]));
		g.add_edge(i, n+1, (ll)(w));
	}
	rep(i, n) {
		int ki;
		cin >> ki;
		rep(j, ki) {
			int cj;
			cin >> cj;
			--cj;
			g.add_edge(cj, i, BIG);
		}
	}
	ll mval = g.flow(n, n+1);
	cout << (sum - mval) << endl;
	return 0;
}
