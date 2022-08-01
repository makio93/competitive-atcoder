// 本番AC

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
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> g(n, vector<bool>(n));
	rep(i, m) {
		int ui, vi;
		cin >> ui >> vi;
		--ui; --vi;
		g[ui][vi] = g[vi][ui] = true;
	}
	int res = 0;
	rep(a, n) rep3(b, a+1, n) if (g[a][b]) {
		rep3(c, b+1, n) if (g[b][c] && g[c][a]) ++res;
	}
	cout << res << endl;
	return 0;
}
