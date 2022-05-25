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
	int n, q;
	cin >> n >> q;
	vector<int> s(n), t(n), x(n);
	rep(i, n) cin >> s[i] >> t[i] >> x[i];
	vector<int> ids(n);
	iota(all(ids), 0);
	sort(all(ids), [&](int li, int ri)-> bool {
		return (x[li] != x[ri]) ? (x[li] < x[ri]) : (make_pair(s[li], t[li]) < make_pair(s[ri], t[ri]));
	});
	map<int, int> d;
	rep(i, q) {
		int di;
		cin >> di;
		d[di] = i;
	}
	vector<int> res(q, -1);
	rep(i, n) if (!d.empty()) {
		auto sitr = d.lower_bound(s[ids[i]]-x[ids[i]]), titr = d.lower_bound(t[ids[i]]-x[ids[i]]);
		auto itr = sitr;
		while (itr != titr) {
			res[itr->second] = x[ids[i]];
			itr = d.erase(itr);
		}
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
