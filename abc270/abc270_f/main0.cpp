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

const ll LINF = (ll)(1e18);

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n), a(m), b(m), z(m);
	rep(i, n) cin >> x[i];
	rep(i, n) cin >> y[i];
	rep(i, m) {
		cin >> a[i] >> b[i] >> z[i];
		a[i]--; b[i]--;
	}
	vector<pair<int, pair<int, int>>> es;
	rep(i, n) es.emplace_back(x[i], make_pair(i, n));
	rep(i, n) es.emplace_back(y[i], make_pair(i, n+1));
	rep(i, m) es.emplace_back(z[i], make_pair(a[i], b[i]));
	sort(all(es));
	vector<dsu> d(4, dsu(n+2));
	ll res = LINF;
	int elen = es.size();
	vector<vector<int>> ban = { {}, { n }, { n+1 }, { n, n+1 } };
	rep(i1, 4) {
		ll val = 0;
		rep(i, elen) {
			if (find(all(ban[i1]),es[i].second.first)!=ban[i1].end() || find(all(ban[i1]),es[i].second.second)!=ban[i1].end()) continue;
			if (!d[i1].same(es[i].second.first, es[i].second.second)) {
				val += es[i].first;
				d[i1].merge(es[i].second.first, es[i].second.second);
			}
		}
		bool ok = true;
		rep3(i, 1, n) if (!d[i1].same(0, i)) ok = false;
		if (ok) res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
