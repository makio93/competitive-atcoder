#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	vector<pair<ll, int>> ql(q);
	rep(i, q) {
		ll ki;
		cin >> ki;
		ql[i] = { ki, i };
	}
	sort(all(ql));
	vector<ll> res(q);
	int m = a.size(), qi = 0;
	while (qi<q && ql[qi].first<a.front()) {
		res[ql[qi].second] = ql[qi].first;
		++qi;
	}
	if (qi < q) {
		rep(i, m-1) {
			ll al = a[i] + 1 - (i+1), ar = a[i+1] - 1 - (i+1);
			while (qi<q && ql[qi].first>=al && ql[qi].first<=ar) {
				res[ql[qi].second] = ql[qi].first + (i+1);
				++qi;
			}
			if (qi >= q) break;
		}
	}
	if (qi < q) {
		while (qi<q) {
			res[ql[qi].second] = ql[qi].first + m;
			++qi;
		}
	}
	rep(i, q) cout << res[i] << endl;
	return 0;
}
