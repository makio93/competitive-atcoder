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
	int h, w, c, q;
	cin >> h >> w >> c >> q;
	vector<int> ti(q), ni(q), ci(q);
	rep(i, q) {
		cin >> ti[i] >> ni[i] >> ci[i];
		ni[i]--; ci[i]--;
	}
	vector<ll> res(c);
	unordered_set<int> hids, wids;
	repr(i, q) {
		ll add = 0;
		if (ti[i] == 1) {
			if (hids.find(ni[i]) == hids.end()) {
				add += w - (int)(wids.size());
				hids.insert(ni[i]);
			}
		}
		else {
			if (wids.find(ni[i]) == wids.end()) {
				add += h - (int)(hids.size());
				wids.insert(ni[i]);
			}
		}
		res[ci[i]] += add;
	}
	rep(i, c) printf("%lld%c", res[i], (i<c-1?' ':'\n'));
	return 0;
}
