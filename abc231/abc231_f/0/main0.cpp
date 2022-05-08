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

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	auto btmp = b;
	sort(all(btmp));
	btmp.erase(unique(all(btmp)), btmp.end());
	int m = btmp.size();
	rep(i, n) {
		int bid = lower_bound(all(btmp), b[i]) - btmp.begin();
		b[i] = bid;
	}
	map<int, vector<int>> ab;
	rep(i, n) ab[a[i]].push_back(b[i]);
	fenwick_tree<int> bval(m);
	ll res = 0;
	for (auto itr=ab.begin(); itr!=ab.end(); ++itr) {
		for (auto bi : itr->second) {
			bval.add(bi, 1);
		}
		for (auto bi : itr->second) {
			res += bval.sum(bi, m);
		}
	}
	cout << res << endl;
	return 0;
}
