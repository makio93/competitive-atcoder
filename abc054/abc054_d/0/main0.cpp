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

const int INF = (int)(1e9);

int main() {
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	map<pair<int, int>, int> lval, rval;
	rep(i, (1<<(n/2))) {
		int ai = 0, bi = 0, ci = 0;
		rep(j, n/2) if ((i>>j)&1) { ai += a[j], bi += b[j], ci += c[j]; }
		if (lval.find({ai, bi}) == lval.end()) lval[{ai, bi}] = ci;
		else lval[{ai, bi}] = min(lval[{ai, bi}], ci);
	}
	rep(i, (1<<(n-n/2))) {
		int ai = 0, bi = 0, ci = 0;
		rep(j, n-n/2) if ((i>>j)&1) { ai += a[n/2+j], bi += b[n/2+j], ci += c[n/2+j]; }
		if (rval.find({ai, bi}) == rval.end()) rval[{ai, bi}] = ci;
		else rval[{ai, bi}] = min(rval[{ai, bi}], ci);
	}
	int tar = 1;
	int res = INF;
	while (ma*tar<=400 && mb*tar<=400) {
		int ta = ma*tar, tb = mb*tar;
		for (auto pi : lval) if (pi.first.first<=ta && pi.first.second<=tb) {
			int ra = ta - pi.first.first, rb = tb - pi.first.second;
			if (rval.find({ra, rb}) != rval.end()) res = min(res, pi.second+rval[{ra, rb}]);
		}
		++tar;
	}
	if (res == INF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
