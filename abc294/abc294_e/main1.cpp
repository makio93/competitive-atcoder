// 解説AC

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
	vector<pair<ll, int>> vlst;
	vlst.emplace_back(0, 0);
	ll tval = 0;
	rep(i, n1) {
		tval += l1[i];
		vlst.emplace_back(tval, 1);
	}
	tval = 0;
	rep(i, n2) {
		tval += l2[i];
		vlst.emplace_back(tval, 2);
	}
	sort(all(vlst));
	ll res = 0;
	int m = vlst.size(), id1 = 0, id2 = 0;
	rep3(i, 1, m) {
		if (id1>=n1 || id2>=n2) break;
		if (v1[id1] == v2[id2]) res += vlst[i].first - vlst[i-1].first;
		if (vlst[i].second == 1) ++id1;
		else ++id2;
	}
	cout << res << endl;
	return 0;
}
