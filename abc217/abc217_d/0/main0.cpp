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
	int l, q;
	cin >> l >> q;
	set<int> cuts;
	cuts.insert(0);
	cuts.insert(l);
	rep(i, q) {
		int ci, xi;
		cin >> ci >> xi;
		if (ci == 1) cuts.insert(xi);
		else {
			auto itr = cuts.lower_bound(xi);
			int ri = *itr, li = *prev(itr);
			cout << (ri-li) << endl;
		}
	}
	return 0;
}
