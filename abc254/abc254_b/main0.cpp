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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> a(n);
	a[0].push_back(1);
	rep3(i, 1, n) {
		a[i] = vector<ll>(i+1);
		rep(j, i+1) {
			ll lval = (j-1 >= 0) ? a[i-1][j-1] : 0;
			ll rval = (j < i) ? a[i-1][j] : 0;
			a[i][j] = lval + rval;
		}
	}
	rep(i, n) rep(j, i+1) printf("%lld%c", a[i][j], (j<i?' ':'\n'));
	return 0;
}
