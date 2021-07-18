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

// 本番AC

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, n) cin >> c[i];
	sort(all(a));
	sort(all(b));
	sort(all(c));
	int res = 0, bid = 0, cid = 0;
	rep(i, n) {
		while (bid<n && b[bid]<=a[i]) ++bid;
		if (bid == n) break;
		while (cid<n && c[cid]<=b[bid]) ++cid;
		if (cid == n) break;
		++res;
		++bid; ++cid;
	}
	cout << res << endl;
	return 0;
}
