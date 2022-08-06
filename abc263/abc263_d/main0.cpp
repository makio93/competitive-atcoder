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

const ll LINF = (ll)(1e18);

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> asum(n+1);
	rep(i, n) asum[i+1] = asum[i] + a[i];
	vector<ll> lsub(n+1);
	rep3(i, 1, n+1) lsub[i] = max(lsub[i-1], asum[i]-(ll)l*i);
	ll res = LINF;
	repr(i, n+1) res = min(res, min(asum[i], asum[i]-lsub[i])+(ll)r*(n-i));
	cout << res << endl;
	return 0;
}
