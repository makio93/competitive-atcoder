// 練習1,自力AC

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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ll res = LINF;
	rep(i, n) rep(j, n) {
		ll val = 0;
		rep(i1, n) {
			val += abs(a[i1]-a[i]);
			val += b[i1] - a[i1];
			val += abs(b[j]-b[i1]);
		}
		res = min(res, val);
	}
	cout << res << endl;
	return 0;
}
