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

const int INF = (int)(1.5e9);
const ll LINF = (ll)(4e18);

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	int bm = INF;
	ll nsum = 0, res = LINF;
	rep(i, n) {
		if (i+1 > x) break;
		nsum += a[i] + b[i];
		bm = min(bm, b[i]);
		ll val = nsum + (ll)(x-(i+1)) * bm;
		res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
