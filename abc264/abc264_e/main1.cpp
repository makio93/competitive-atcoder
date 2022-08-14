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
	int n, m, e, q;
	cin >> n >> m >> e;
	vector<int> u(e), v(e);
	rep(i, e) {
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	cin >> q;
	vector<int> x(q);
	rep(i, q) {
		cin >> x[i];
		x[i]--;
	}
	vector<bool> fl(e, true), el(n+m);
	rep(i, q) fl[x[i]] = false;
	rep3(i, n, n+m) el[i] = true;
	dsu d(n+m);
	int nval = 0;
	rep(i, e) if (fl[i]) {
		if (d.same(u[i], v[i])) continue;
		if (el[d.leader(u[i])] ^ el[d.leader(v[i])]) {
			if (!el[d.leader(u[i])]) nval += d.size(u[i]);
			else nval += d.size(v[i]);
			el[d.leader(u[i])] = el[d.leader(v[i])] = true;
		}
		d.merge(u[i], v[i]);
	}
	vector<int> res(q);
	repr(i, q) {
		res[i] = nval;
		if (d.same(u[x[i]], v[x[i]])) continue;
		if (el[d.leader(u[x[i]])] ^ el[d.leader(v[x[i]])]) {
			if (!el[d.leader(u[x[i]])]) nval += d.size(u[x[i]]);
			else nval += d.size(v[x[i]]);
			el[d.leader(u[x[i]])] = el[d.leader(v[x[i]])] = true;
		}
		d.merge(u[x[i]], v[x[i]]);
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
