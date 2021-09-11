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
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
	}
	vector<pair<int, int>> ce(m);
	rep(i, m) ce[i] = { c[i], i };
	sort(all(ce));
	dsu d(n);
	unordered_set<int> elst;
	rep(i, m) elst.insert(i);
	rep(i, m) {
		int ai = a[ce[i].second], bi = b[ce[i].second];
		if (!d.same(ai, bi)) {
			d.merge(ai, bi);
			elst.erase(ce[i].second);
		}
	}
	ll res = 0;
	for (int ei : elst) if (c[ei] > 0) res += c[ei];
	cout << res << endl;
	return 0;
}
