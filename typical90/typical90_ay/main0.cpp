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

// 自力AC

int main() {
	int n, k; ll p;
	cin >> n >> k >> p;
	vector<ll> a(n), ar;
	rep(i, n) cin >> a[i];
	rep3(i, n/2+1, n) ar.push_back(a[i]);
	int rlen = (int)(ar.size()), llen = n - rlen;
	vector<vector<ll>> rval(k+1);
	rep(i, (1<<rlen)) {
		ll rvali = 0; int bcnt = 0;
		rep(j, rlen) if ((i>>j) & 1) {
			rvali += ar[j];
			++bcnt;
		}
		if (bcnt <= k) rval[bcnt].push_back(rvali);
	}
	rep(i, k+1) if (!rval[i].empty()) sort(all(rval[i]));
	ll res = 0;
	rep(i, (1<<llen)) {
		ll lvali = 0; int bcnt = 0;
		rep(j, llen) if ((i>>j) & 1) {
			lvali += a[j];
			++bcnt;
		}
		if (k-bcnt>=0 && p-lvali>=0) res += upper_bound(all(rval[k-bcnt]), p-lvali) - rval[k-bcnt].begin();
	}
	cout << res << endl;
	return 0;
}
