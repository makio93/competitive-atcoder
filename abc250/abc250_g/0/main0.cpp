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

const int INF = (int)(2e9);
pair<int, int> op(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> e() { return make_pair(INF, -1); }

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	set<pair<int, int>> plst;
	rep(i, n) plst.emplace(p[i], i);
	segtree<pair<int, int>, op, e> st(n);
	rep(i, n) st.set(i, make_pair(p[i], i));
	ll res = 0;
	while (!plst.empty()) {
		auto itr = plst.rbegin();
		int aval = itr->first, aid = itr->second;
		plst.erase({ aval, aid });
		auto bp = st.prod(0, aid+1);
		int bval = bp.first, bid = bp.second;
		if (bval < aval) res += aval - bval;
		st.set(aid, make_pair(INF, aid));
		if (bid < aid) {
			plst.erase({ bval, bid });
			st.set(bid, make_pair(INF, bid));
		}
	}
	cout << res << endl;
	return 0;
}
