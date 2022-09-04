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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> asum(n+1), bvals(n), bsum(n+1);
	rep(i, n) asum[i+1] = asum[i] + a[i];
	rep(i, n) bvals[i] = (ll)a[i] * (i+1);
	rep(i, n) bsum[i+1] = bsum[i] + bvals[i];
	ll res = -LINF;
	for (int i=0; i+m<=n; ++i) res = max(res, (bsum[i+m]-bsum[i])-(asum[i+m]-asum[i])*i);
	cout << res << endl;
	return 0;
}
