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

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	scc_graph sg(n);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		--ai; --bi;
		sg.add_edge(ai, bi);
	}
	auto gl = sg.scc();
	int len = gl.size();
	if ((int)(gl.size()) == n) {
		rep(i, k) rep(j, n) printf("%d%c", gl[j].front()+1, (j<n-1?' ':'\n'));
	}
	else cout << -1 << endl;
	return 0;
}
