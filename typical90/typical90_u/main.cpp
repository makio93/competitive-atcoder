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

// 自力AC

int main() {
	int n, m;
	cin >> n >> m;
	scc_graph g(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		g.add_edge(ai, bi);
	}
	auto lst = g.scc();
	ll res = 0;
	for (auto li : lst) {
		int lcnt = (int)(li.size());
		res += (ll)lcnt * (lcnt - 1) / 2;
	}
	cout << res << endl;
	return 0;
}
