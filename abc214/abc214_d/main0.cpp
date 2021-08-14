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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> edges(n-1);
	rep(i, n-1) {
		int ui, vi, wi;
		cin >> ui >> vi >> wi;
		--ui; --vi;
		if (ui > vi) swap(ui, vi);
		edges[i] = { wi, { ui, vi } };
	}
	sort(all(edges));
	dsu d(n);
	ll res = 0;
	rep(i, n-1) {
		res += (ll)d.size(edges[i].second.first) * d.size(edges[i].second.second) * edges[i].first;
		d.merge(edges[i].second.first, edges[i].second.second);
	}
	cout << res << endl;
	return 0;
}
