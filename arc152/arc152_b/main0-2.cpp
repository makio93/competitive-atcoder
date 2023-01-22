// 自力AC

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
const ll LINF = (ll)(1e18);

int main() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	auto calc = [&](int cid, int sid) -> ll {
		return (ll)max(a[cid]+a[sid], (l-a[cid])+(l-a[sid])) * 2;
	};
	ll res = LINF;
	rep(i, n) {
		int id = upper_bound(all(a), l-a[i]) - a.begin();
		if (id < n) res = min(res, calc(i, id));
		if (id-1 >= 0) res = min(res, calc(i, id-1));
	}
	cout << res << endl;
	return 0;
}
