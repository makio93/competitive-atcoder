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
	ll l;
	int n1, n2;
	cin >> l >> n1 >> n2;
	vector<int> v1(n1), v2(n2);
	vector<ll> l1(n1), l2(n2);
	rep(i, n1) cin >> v1[i] >> l1[i];
	rep(i, n2) cin >> v2[i] >> l2[i];
	map<ll, pair<ll, int>> vlst;
	ll val = 0;
	rep(i, n1) {
		vlst[val+1] = { val+l1[i], v1[i] };
		val += l1[i];
	}
	ll res = 0;
	val = 0;
	rep(i, n2) {
		ll lval = val + 1, rval = val + l2[i];
		int tval = v2[i];
		auto litr = prev(vlst.upper_bound(lval)), ritr = vlst.upper_bound(rval);
		for (auto itr=litr; itr!=ritr; ++itr) if (itr->second.second == tval) {
			res += itr->second.first - itr->first + 1;
			if (itr == litr) res -= lval - itr->first;
			if (itr == prev(ritr)) res -= itr->second.first - rval;
		}
		val += l2[i];
	}
	cout << res << endl;
	return 0;
}
