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

// 自力で作成、WA
// その1：フローを流してみる

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> c(m), l(m), r(m);
	rep(i, m) {
		cin >> c[i] >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	mcf_graph<int, ll> g(n+m+3);
	rep(i, m) g.add_edge(n+m+1, n+1+i, 1, c[i]);
	rep(i, m) g.add_edge(n+1+i, l[i], 1, 0);
	rep(i, m) g.add_edge(n+1+i, r[i]+1, 1, 0);
	rep(i, n+1) g.add_edge(i, n+m+2, 1, 0);
	pair<int, ll> fval = g.flow(n+m+1, n+m+2, n+1);
	if (fval.first < n+1) cout << -1 << endl;
	else cout << (fval.second) << endl;
	return 0;
}
