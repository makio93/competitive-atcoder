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
	unordered_set<int> xlst;
	rep(i, e) xlst.insert(i);
	rep(i, q) xlst.erase(x[i]);
	dsu d(n+m);
	for (int xi : xlst) d.merge(u[xi], v[xi]);
	unordered_set<int> fids, sids;
	rep(i, n+m) sids.insert(d.leader(i));
	rep3(i, n, n+m) if (sids.find(d.leader(i)) != sids.end()) {
		sids.erase(d.leader(i));
		fids.insert(d.leader(i));
	}
	int nval = 0;
	for (int id : fids) nval += d.size(id);
	nval -= m;
	vector<int> res(q);
	repr(i, q) {
		res[i] = nval;
		if (sids.find(d.leader(u[x[i]]))!=sids.end() && fids.find(d.leader(v[x[i]]))!=fids.end()) {
			nval += d.size(u[x[i]]);
			sids.erase(d.leader(u[x[i]]));
			fids.insert(d.leader(u[x[i]]));
		} 
		else if (sids.find(d.leader(v[x[i]]))!=sids.end() && fids.find(d.leader(u[x[i]]))!=fids.end()) {
			nval += d.size(v[x[i]]);
			sids.erase(d.leader(v[x[i]]));
			fids.insert(d.leader(v[x[i]]));
		}
		d.merge(u[x[i]], v[x[i]]);
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
