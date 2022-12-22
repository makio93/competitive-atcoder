// 自力,WA

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

const ll INF = (ll)(1e12);

int main() {
	int n;
	cin >> n;
	vector<int> a(2*n);
	rep(i, 2*n) cin >> a[i];
	vector<map<int, unordered_set<int>>> avals(2);
	rep(i, 2*n) avals[i%2][a[i]].insert(i);
	vector<vector<int>> elst(2*n);
	rep(i, 2*n) {
		avals[i%2][a[i]].erase(i);
		if (avals[i%2][a[i]].empty()) avals[i%2].erase(a[i]);
		if (avals[(i+1)%2].empty()) continue;
		int rid1 = *avals[(i+1)%2].begin()->second.begin();
		int rid2 = *avals[(i+1)%2].rbegin()->second.begin();
		elst[i].push_back(rid1);
		if (rid2 != rid1) elst[i].push_back(rid2);
	}
	mcf_graph<int, ll> g(4*n+2);
	rep(i, 2*n) g.add_edge(4*n, i, 1, 0);
	rep(i, 2*n) g.add_edge(2*n+i, 4*n+1, 1, 0);
	rep(i, 2*n) {
		for (int ti : elst[i]) {
			ll cval = INF - abs(a[i]-a[ti]);
			g.add_edge(i, 2*n+ti, 1, cval);
		}
	}
	g.flow(4*n, 4*n+1, n);
	auto es = g.edges();
	string res(2*n, '.');
	for (auto& ei : es) if (ei.from<2*n && ei.to>=2*n && ei.to<4*n) {
		if (ei.flow == 1) {
			res[ei.from] = '(';
			res[ei.to-2*n] = ')';
		}
	}
	cout << res << endl;
	return 0;
}
