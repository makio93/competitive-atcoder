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

const ll LINF = (ll)(1e18);

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> lvals(n+1);
	rep(i, n) lvals[i+1] = min(lvals[i]+a[i], (ll)l*(i+1));
	ll res = lvals[n], rval = 0;
	repr(i, n) {
		rval = min(rval+a[i], (ll)r*(n-i));
		res = min(res, lvals[i]+rval);
	}
	cout << res << endl;
	return 0;
}
