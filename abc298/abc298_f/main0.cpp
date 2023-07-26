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
	int n;
	cin >> n;
	vector<int> r(n), c(n), x(n);
	rep(i, n) cin >> r[i] >> c[i] >> x[i];
	unordered_map<int, ll> rsum, csum;
	rep(i, n) {
		rsum[r[i]] += x[i];
		csum[c[i]] += x[i];
	}
	ll res = 0;
	rep(i, n) res = max(res, rsum[r[i]]+csum[c[i]]-x[i]);
	multiset<ll> clst;
	for (const auto& pi : csum) clst.insert(pi.second);
	unordered_map<int, unordered_set<int>> rcids;
	rep(i, n) rcids[r[i]].insert(c[i]);
	for (const auto& pi : rcids) {
		for (const int& ti : pi.second) clst.erase(clst.find(csum[ti]));
		if (!clst.empty()) res = max(res, rsum[pi.first]+*clst.rbegin());
		for (const int& ti : pi.second) clst.insert(csum[ti]);
	}
	cout << res << endl;
	return 0;
}
