// 本番,TLE

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
	int n, m, q;
	cin >> n >> m >> q;
	fenwick_tree<ll> as(m+1);
	unordered_map<int, fenwick_tree<ll>> ts;
	rep(i, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int li, ri, xi;
			cin >> li >> ri >> xi;
			--li;
			as.add(li, xi);
			as.add(ri, -xi);
		}
		else if (qi == 2) {
			int id, xi;
			cin >> id >> xi;
			--id;
			ts[id] = as;
			ts[id].add(0, -xi);
			ts[id].add(m, xi);
		}
		else {
			int ii, ji;
			cin >> ii >> ji;
			--ii;
			ll res = as.sum(0, ji);
			if (ts.find(ii) != ts.end()) {
				res -= ts[ii].sum(0, ji);
			}
			cout << res << endl;
		}
	}
	return 0;
}
