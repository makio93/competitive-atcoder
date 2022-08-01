// 本番WA

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
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	if (k==0 || n==1) {
		rep(i, n) cout << p[i] << (i<n-1?' ':'\n');
		return 0;
	}
	if (n == 2) {
		cout << min(p[0], p[1]) << endl;
		return 0;
	}
	pair<int, int> lval = { INF, -1 }, rval = { INF, -1 };
	rep(i, k) lval = min(lval, { p[i], i });
	rep(i, k) rval = min(rval, { p[n-1-i], n-1-i });
	list<int> pvals;
	rep(i, n) pvals.push_back(p[i]);
	if (rval.first < lval.first) {
		auto itr = prev(pvals.end());
		rep(i, (n-rval.second)) {
			pvals.push_front(*itr);
			itr = prev(pvals.erase(itr));
		}
	}
	else {
		auto itr = pvals.begin();
		rep(i, lval.second) itr = pvals.erase(itr);
		k -= lval.second;
	}
	auto itr = next(pvals.begin());
	while (k > 0) {
		if (itr == pvals.end()) break;
		if (next(itr) == pvals.end()) {
			itr = pvals.erase(itr);
			--k;
			break;
		}
		if (*next(itr) < *itr) {
			itr = prev(pvals.erase(itr));
			--k;
		}
		if (*next(itr) > *itr) ++itr;
	}
	vector<int> res;
	itr = pvals.begin();
	while (itr != pvals.end()) {
		res.push_back(*itr);
		++itr;
	}
	int rlen = res.size();
	rep(i, rlen) cout << res[i] << (i<rlen-1?' ':'\n');
	return 0;
}
